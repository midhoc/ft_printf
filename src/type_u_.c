/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 02:39:19 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:39:31 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_digit_u(t_ft_printf *tst, unsigned long long int nb)
{
	long int	counter;

	counter = 0;
	if (nb == 0 && tst->precision == 0)
		return (0);
	while (nb > 9)
	{
		nb /= 10;
		counter++;
	}
	return (counter + 1);
}

static void	put_u_op_mns(t_ft_printf *tst,
							unsigned long long int nbr, int c)
{
	tst->width -= (ft_max(c, tst->precision));
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr != 0)
		ft_putnbr_unsigned_buf(nbr, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
	while (tst->width-- > 0)
		ft_putchar_buff(' ', tst);
}

static void	put_u_op_0(t_ft_printf *tst, unsigned long long int nbr, int c)
{
	if (tst->precision >= 0)
	{
		tst->width -= (ft_max(c, tst->precision));
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
	}
	else
		tst->precision = tst->width;
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr != 0)
		ft_putnbr_unsigned_buf(nbr, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
}

void		put_u(t_ft_printf *tst, unsigned long long int nbr)
{
	int		c;
	int		i;

	i = 0;
	c = count_digit_u(tst, nbr);
	if (tst->op_mns)
		put_u_op_mns(tst, nbr, c);
	else if (tst->op_0)
		put_u_op_0(tst, nbr, c);
	else
	{
		tst->width -= (ft_max(c, tst->precision));
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		if (nbr != 0)
			ft_putnbr_unsigned_buf(nbr, tst);
		else if (tst->precision)
			ft_putchar_buff('0', tst);
	}
}
