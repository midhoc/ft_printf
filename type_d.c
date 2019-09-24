/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:25:19 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/24 02:51:44 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				max(int i, int ii)
{
	if(i < ii)
		return (ii);
	return(i);
}

int				count_digit_d(t_ft_printf *tst, long long int nbr)
{
	long int				counter;
	unsigned long long int	nb;

	counter = 0;

	if (nbr < 0)
		nb = -1 * nbr;
	else if (nbr > 0)
		nb = nbr;
	// if(nbr < 0 || tst->op_pls || tst->op_sp)
	// 	counter++;
	else if (nbr == 0 && tst->precision == 0)
	 	return (0);
	while (nb > 9)
	{
		nb /= 10;
		counter++;
	}
	return (counter + 1);
}

int				put_sign(t_ft_printf *tst, long long int nbr)
{
	if (nbr < 0)
		write(1,"-", 1);
	else if (tst->op_pls)
		write(1, "+", 1);
	else if (tst->op_sp)
		write(1, " ", 1);
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
		tst->width -= (put_sign(tst, nbr) + max(c, tst->precision));
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr < 0)
			ft_putnbr_unsigned((unsigned long long)nbr * -1);
		else if (nbr > 0)
			ft_putnbr_unsigned((unsigned long long)nbr);
		else if (tst->precision)
			write(1, "0", 1);
		while (tst->width-- >0)
			write(1, " ", 1);
	}
	else if(tst->op_0)
	{

		if (tst->precision >= 0)
		{
			tst->width -= (put_sign(tst, nbr) + max(c, tst->precision));
			while (tst->width-- >0)
				write(1, " ", 1);
		}
		else
			tst->precision = tst->width - put_sign(tst, nbr);
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr < 0)
			ft_putnbr_unsigned((unsigned long long)nbr * -1);
		else if (nbr > 0)
			ft_putnbr_unsigned((unsigned long long)nbr);
		else if (tst->precision)
			write(1, "0", 1);
	}
	else
	{
		while (max(c, tst->precision) < tst->width--)
			write(1, " ", 1);
		if (nbr < 0)
			write(1,"-", 1);
		else if (tst->op_pls)
			write(1, "+", 1);
		else if (tst->op_sp)
			write(1, " ", 1);
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr)
		{
			/* code */
		}
		if (nbr > 0)
			ft_putnbr(nbr);
		else if (nbr < 0)
			ft_putnbr((unsigned long long)nbr * -1);
		else if (tst->precision)
			write(1, "0", 1);
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
	put_d(tst, (long int)c);
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
	else
	{
		c = va_arg(argv, int);
		put_d(tst, c);
	}
	return(1);
}
