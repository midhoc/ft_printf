/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:28:59 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/26 03:25:44 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s_op_mns(t_ft_printf *tst, int i, char *c)
{
	if(tst->precision >= 0 && tst->precision < i)
	{
		while(tst->precision--)
			ft_putchar(*(c++));
	}
	else
	{
		while(*c)
			ft_putchar(*(c++));
	}
	while (tst->width-- > 0)
		ft_putchar(' ');
}

void	type_s_op(t_ft_printf *tst, int i, char *c)
{
	while (tst->width-- > 0)
	{
		if (tst->op_0)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if(tst->precision >= 0 && tst->precision < i)
	{
		while(tst->precision--)
			ft_putchar(*(c++));
	}
	else
	{
		while(*c)
			ft_putchar(*(c++));
	}
}


int		type_s_(t_ft_printf *tst, va_list argv)
{
	char	*c;
	int		i;

	c = va_arg(argv, char *);
	if (!c)
		c = "(null)";
	i = ft_strlen(c);
	tst->width -= ft_min(i, (tst->precision < 0) ? i : tst->precision);
	if (tst->op_mns)
		type_s_op_mns(tst, i, c);
	else
		type_s_op(tst, i, c);
	return(1);
}

int		type_s(t_ft_printf *tst, va_list argv)
{
	if (tst->length == L)
		type_s_l(tst, argv);
	else
	{
		type_s_(tst, argv);
	}

	return(1);
}
