/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 05:09:39 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:38:11 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_digit_d(t_ft_printf *tst, long long int nbr)
{
	long int				counter;
	unsigned long long int	nb;

	counter = 0;
	nb = 0;
	if (nbr < 0)
		nb = -1 * nbr;
	else if (nbr > 0)
		nb = nbr;
	else if (nbr == 0 && tst->precision == 0)
		return (0);
	while (nb > 9)
	{
		nb /= 10;
		counter++;
	}
	return (counter + 1);
}

static int		put_sign(t_ft_printf *tst, long long int nbr, int flag)
{
	if (flag && (nbr < 0 || tst->op_pls || tst->op_sp))
		return (1);
	if (nbr < 0)
		ft_putchar_buff('-', tst);
	else if (tst->op_pls)
		ft_putchar_buff('+', tst);
	else if (tst->op_sp)
		ft_putchar_buff(' ', tst);
	else
		return (0);
	return (1);
}

static void		type_d_op_mns(t_ft_printf *tst, long long int nbr, int c)
{
	tst->width -= (put_sign(tst, nbr, 0) + ft_max(c, tst->precision));
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr < 0)
		ft_putnbr_unsigned_buf((unsigned long long)nbr * -1, tst);
	else if (nbr > 0)
		ft_putnbr_unsigned_buf((unsigned long long)nbr, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
	while (tst->width-- > 0)
		ft_putchar_buff(' ', tst);
}

static void		type_d_op_0(t_ft_printf *tst, long long int nbr, int c)
{
	if (tst->precision >= 0)
	{
		tst->width -= (put_sign(tst, nbr, !tst->op_0)
			+ ft_max(c, tst->precision));
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
	}
	else
		tst->precision = tst->width - put_sign(tst, nbr, !tst->op_0);
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr < 0)
		ft_putnbr_unsigned_buf((unsigned long long)nbr * -1, tst);
	else if (nbr > 0)
		ft_putnbr_unsigned_buf((unsigned long long)nbr, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
}

void			put_d(t_ft_printf *tst, long long int nbr)
{
	int		c;

	c = count_digit_d(tst, nbr);
	if (tst->op_mns)
		type_d_op_mns(tst, nbr, c);
	else if (tst->op_0)
		type_d_op_0(tst, nbr, c);
	else
	{
		tst->width -= (put_sign(tst, nbr, 1) + ft_max(c, tst->precision));
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
		put_sign(tst, nbr, 0);
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		if (nbr < 0)
			ft_putnbr_unsigned_buf((unsigned long long)nbr * -1, tst);
		else if (nbr > 0)
			ft_putnbr_unsigned_buf((unsigned long long)nbr, tst);
		else if (tst->precision)
			ft_putchar_buff('0', tst);
	}
}
