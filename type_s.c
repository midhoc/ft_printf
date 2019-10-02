/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:28:59 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:12:50 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s_op_mns(t_ft_printf *tst, int i, char *c)
{
	if(tst->precision >= 0 && tst->precision < i)
	{
		while(tst->precision--)
			ft_putchar_buff(*(c++), tst);
	}
	else
	{
		while(*c)
			ft_putchar_buff(*(c++), tst);
	}
	while (tst->width-- > 0)
		ft_putchar_buff(' ', tst);
}

void	type_s_op(t_ft_printf *tst, int i, char *c)
{
	while (tst->width-- > 0)
	{
		if (tst->op_0)
			ft_putchar_buff('0', tst);
		else
			ft_putchar_buff(' ', tst);
	}
	if(tst->precision >= 0 && tst->precision < i)
	{
		while(tst->precision--)
			ft_putchar_buff(*(c++), tst);
	}
	else
	{
		while(*c)
			ft_putchar_buff(*(c++), tst);
	}
}


void	type_s_(t_ft_printf *tst, va_list argv)
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
}

void	type_s(t_ft_printf *tst, va_list argv)
{
	if (tst->length == L)
		type_s_l(tst, argv);
	else
		type_s_(tst, argv);
}
