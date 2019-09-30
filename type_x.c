/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:40:16 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/30 02:47:35 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_sign(t_ft_printf *tst,unsigned long long int nbr, int flag, int flag_up)
{
	if (flag && tst->op_htg)
		return (2);
	if (tst->op_htg)
	{
		if (flag_up)
			write(1,"0X", 2);
		else
			write(1,"0x", 2);
		return (2);
	}
	return (0);
}

void			put_x(t_ft_printf *tst, unsigned long long int nbr, int flag_up)
{
	int		c;
	int		i;
	char	*str;

	i = 0;
	if(!(str = ft_itoa_base(nbr, 16, flag_up)))
		return;
	c = ft_strlen(str);
	if (tst->op_mns)
	{
		tst->width -= (put_sign(tst, nbr, 0, flag_up) + ft_max(c, tst->precision));
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr > 0)
			ft_putstr(str);
		else if (tst->precision > 0)
			write(1, "0", 1);
		while (tst->width-- > 0)
			write(1, " ", 1);
	}
	else if (tst->op_0)
	{
		if (tst->precision >= 0)
		{
			tst->width -= (put_sign(tst, nbr, !tst->op_0, flag_up) + ft_max(c, tst->precision));
			while (tst->width-- >0)
				write(1, " ", 1);
		}
		else
			tst->precision = tst->width - put_sign(tst, nbr, !tst->op_0, flag_up);
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr > 0)
			ft_putstr(str);
		else if (tst->precision > 0)
			write(1, "0", 1);
	}
	else
	{
		tst->width -= (put_sign(tst, nbr, 1, flag_up) + ft_max(c, tst->precision));
		while (tst->width-- >0)
			write(1, " ", 1);
		put_sign(tst, nbr, 0, flag_up);
		while (c++ < tst->precision)
			write(1, "0", 1);
		if (nbr > 0)
			ft_putstr(str);
		else if (tst->precision > 0)
			write(1, "0", 1);
	}
	free(str);
}

static int		type_x_hh(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned int c;

	c = va_arg(argv, unsigned int);
	if (tst->length == HH)
		put_x(tst, (unsigned char)c, flag_up);
	else
		put_x(tst, (unsigned short int)c, flag_up);
	return(1);
}

static int		type_x_ll(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned long long int c;

	c = va_arg(argv, unsigned long long int);
	put_x(tst, c, flag_up);
	return(1);
}

static int		type_x_l(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_x(tst, c, flag_up);
	return(1);
}


int		type_x(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned int	c;

	if (tst->length == HH || tst->length == H)
		type_x_hh(tst, argv, flag_up);
	else if(tst->length == LL)
		type_x_ll(tst, argv, flag_up);
	else if(tst->length == L)
		type_x_l(tst, argv, flag_up);
	else
	{
		c = va_arg(argv, unsigned int);
		put_x(tst, c, flag_up);
	}
	return(1);
}
