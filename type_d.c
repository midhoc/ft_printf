/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:25:19 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 18:58:14 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				count_digit_d(t_ft_printf *tst, long long int nbr)
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

int				put_sign(t_ft_printf *tst, long long int nbr, int flag)
{
	if (flag && (nbr < 0 || tst->op_pls || tst->op_sp))
		return(1);
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

void			put_d(t_ft_printf *tst, long long int nbr)
{
	int		c;
	int		i;

	i = 0;
	c = count_digit_d(tst, nbr);
	if (tst->op_mns)
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
		while (tst->width-- >0)
			ft_putchar_buff(' ', tst);
	}
	else if (tst->op_0)
	{
		if (tst->precision >= 0)
		{
			tst->width -= (put_sign(tst, nbr, !tst->op_0) + ft_max(c, tst->precision));
			while (tst->width-- >0)
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
	else
	{
		tst->width -= (put_sign(tst, nbr, 1) + ft_max(c, tst->precision));
		while (tst->width-- >0)
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

static int		type_d_hh(t_ft_printf *tst, va_list argv)
{
	int c;

	c = va_arg(argv, int);
	if (tst->length == HH)
		put_d(tst, (signed char)c);
	else
		put_d(tst, (short int)c);
	return(1);
}

static int		type_d_ll(t_ft_printf *tst, va_list argv)
{
	long long int c;

	c = va_arg(argv, long long int);
	put_d(tst, c);
	return(1);
}

static int		type_d_l(t_ft_printf *tst, va_list argv)
{
	long int c;

	c = va_arg(argv, long int);
	put_d(tst, c);
	return(1);
}

static int		type_d_z(t_ft_printf *tst, va_list argv)
{
	size_t c;

	c = va_arg(argv, size_t);
	put_d(tst, c);
	return(1);
}

static int		type_d_j(t_ft_printf *tst, va_list argv)
{
	intmax_t c;

	c = va_arg(argv, intmax_t);
	put_d(tst, c);
	return(1);
}

int		type_d(t_ft_printf *tst, va_list argv)
{
	int c;

	if (tst->length == HH || tst->length == H)
		type_d_hh(tst, argv);
	else if(tst->length == LL)
		type_d_ll(tst, argv);
	else if(tst->length == L)
		type_d_l(tst, argv);
	else if(tst->length == J)
		type_d_j(tst, argv);
	else if(tst->length == Z)
		type_d_z(tst, argv);
	else
	{
		c = va_arg(argv, int);
		put_d(tst, c);
	}
	return(1);
}
