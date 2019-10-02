/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 03:59:49 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:13:55 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				count_digit_u(t_ft_printf *tst, unsigned long long int nb)
{
	long int				counter;

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

void			put_u(t_ft_printf *tst,unsigned long long int nbr)
{
	int		c;
	int		i;

	i = 0;
	c = count_digit_u(tst, nbr);
	if (tst->op_mns)
	{
		tst->width -= ( ft_max(c, tst->precision));
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		if (nbr != 0)
			ft_putnbr_unsigned_buf(nbr, tst);
		else if (tst->precision)
			ft_putchar_buff('0', tst);
		while (tst->width-- >0)
			ft_putchar_buff(' ', tst);
	}
	else if (tst->op_0)
	{
		if (tst->precision >= 0)
		{
			tst->width -= (ft_max(c, tst->precision));
			while (tst->width-- >0)
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
	else
	{
		tst->width -= (ft_max(c, tst->precision));
		while (tst->width-- >0)
			ft_putchar_buff(' ', tst);
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		if (nbr != 0)
			ft_putnbr_unsigned_buf(nbr, tst);
		else if (tst->precision)
			ft_putchar_buff('0', tst);
	}
}


static void	type_u_hh(t_ft_printf *tst, va_list argv)
{
	int c;

	c = va_arg(argv, int);
	if (tst->length == HH)
		put_u(tst, (unsigned  char)c);
	else
		put_u(tst, (unsigned  int)c);
}

static void	type_u_ll(t_ft_printf *tst, va_list argv)
{
	unsigned long long int c;

	c = va_arg(argv,unsigned  long long int);
	put_u(tst, c);
}

static void	type_u_l(t_ft_printf *tst, va_list argv)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_u(tst, c);
}

static void	type_u_z(t_ft_printf *tst, va_list argv)
{
	size_t c;

	c = va_arg(argv, size_t);
	put_u(tst, c);
}

static void	type_u_j(t_ft_printf *tst, va_list argv)
{
	uintmax_t c;

	c = va_arg(argv, uintmax_t);
	put_u(tst, c);
}

void	type_u(t_ft_printf *tst, va_list argv)
{
	unsigned int c;

	if (tst->type == 12)
		type_u_ll(tst, argv);
	else if (tst->length == HH || tst->length == H)
		type_u_hh(tst, argv);
	else if(tst->length == LL)
		type_u_ll(tst, argv);
	else if(tst->length == L)
		type_u_l(tst, argv);
	else if(tst->length == J)
		type_u_j(tst, argv);
	else if(tst->length == Z)
		type_u_z(tst, argv);
	else
	{
		c = va_arg(argv, unsigned int);
		put_u(tst, c);
	}
}
