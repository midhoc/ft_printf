/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 03:59:49 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/24 04:14:46 by hmidoun          ###   ########.fr       */
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
			write(1, "0", 1);
		if (nbr > 0)
			ft_putnbr_unsigned(nbr);
		else if (tst->precision)
			write(1, "0", 1);
		while (tst->width-- >0)
			write(1, " ", 1);
	}
	else //else if (tst->op_0)
	{
		if (tst->precision >= 0)
		{
			tst->width -= (ft_max(c, tst->precision));
			while (tst->width-- >0)
				write(1, " ", 1);
		}
		else
			tst->precision = tst->width;
		if (tst->op_0)
		{
			while (c++ < tst->precision)
				write(1, "0", 1);
		}
		else
		{
			while (c++ < tst->precision)
				write(1, " ", 1);
		}
		if (nbr > 0)
			ft_putnbr_unsigned(nbr);
		else if (tst->precision)
			write(1, "0", 1);
	}
}


static int		type_u_hh(t_ft_printf *tst, va_list argv)
{
	int c;

	c = va_arg(argv, int);
	if (tst->length == HH)
		put_u(tst, (unsigned  char)c);
	else
		put_u(tst, (unsigned  int)c);
	return(1);
}

static int		type_u_ll(t_ft_printf *tst, va_list argv)
{
	unsigned long long int c;

	c = va_arg(argv,unsigned  long long int);
	put_u(tst, c);
	return(1);
}

static int		type_u_l(t_ft_printf *tst, va_list argv)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_u(tst, c);
	return(1);
}

int		type_u(t_ft_printf *tst, va_list argv)
{
	unsigned int c;

	if (tst->length == HH || tst->length == H)
		type_u_hh(tst, argv);
	else if(tst->length == LL)
		type_u_ll(tst, argv);
	else if(tst->length == L)
		type_u_l(tst, argv);
	else
	{
		c = va_arg(argv, unsigned int);
		put_u(tst, c);
	}
	return(1);
}