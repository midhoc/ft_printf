/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:13:02 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/30 02:59:17 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_sign(t_ft_printf *tst,unsigned long long int nbr, int flag)
{
	if (flag && tst->op_htg)
		return (1);
	if (tst->op_htg)
	{
		write(1,"0", 1);
		return (1);
	}
	return (0);
}

void			put_o(t_ft_printf *tst, unsigned long long int nbr)
{
	int		c;
	int		i;
	char	*str;

	i = 0;
	if(!(str = ft_itoa_base(nbr, 8, 0)))
		return;
	c = ft_strlen(str);
	if (tst->op_mns)
	{
		tst->width -= (put_sign(tst, nbr, 0) + ft_max(c, tst->precision));
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr > 0)
			ft_putstr(str);
		else if (tst->precision)
			write(1, "0", 1);
		while (tst->width-- > 0)
			write(1, " ", 1);
	}
	else if (tst->op_0)
	{
		if (tst->precision >= 0)
		{
			tst->width -= (put_sign(tst, nbr, !tst->op_0) + ft_max(c, tst->precision));
			while (tst->width-- >0)
				write(1, " ", 1);
		}
		else
			tst->precision = tst->width - put_sign(tst, nbr, !tst->op_0);
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr > 0)
			ft_putstr(str);
		else if (tst->precision)
			write(1, "0", 1);
	}
	else
	{
		tst->width -= (put_sign(tst, nbr, 1) + ft_max(c, tst->precision));
		while (tst->width-- >0)
			write(1, " ", 1);
		put_sign(tst, nbr, 0);
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr > 0)
			ft_putstr(str);
		else if (tst->precision)
			write(1, "0", 1);
	}
	free(str);
}

static int		type_o_hh(t_ft_printf *tst, va_list argv)
{
	unsigned int c;

	c = va_arg(argv, unsigned int);
	if (tst->length == HH)
		put_o(tst, (unsigned char)c);
	else
		put_o(tst, (unsigned short int)c);
	return(1);
}

static int		type_o_ll(t_ft_printf *tst, va_list argv)
{
	unsigned long long int c;

	c = va_arg(argv, unsigned long long int);
	put_o(tst, c);
	return(1);
}

static int		type_o_l(t_ft_printf *tst, va_list argv)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_o(tst, c);
	return(1);
}


int		type_o(t_ft_printf *tst, va_list argv)
{
	unsigned int	c;

	if (tst->length == HH || tst->length == H)
		type_o_hh(tst, argv);
	else if(tst->length == LL)
		type_o_ll(tst, argv);
	else if(tst->length == L)
		type_o_l(tst, argv);
	else
	{
		c = va_arg(argv, unsigned int);
		put_o(tst, c);
	}
	return(1);
}
