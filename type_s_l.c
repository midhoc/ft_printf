/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:48:13 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:12:51 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_wchar_t(int *str)
{
	int	i;

	i = -1;
	while(str[++i]);
	return(i);
}

void	type_s_l_op_mns(t_ft_printf *tst, int i, int *c)
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

void	type_s_l_op(t_ft_printf *tst, int i, int *c)
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

void		type_s_l(t_ft_printf *tst, va_list argv)
{
	int	*c;
	int	i;

	c = va_arg(argv, int *);
	if (!c)
		ft_putstr_buf("(null)", tst);
	i = ft_strlen_wchar_t(c);
	tst->width -= ft_min(i, (tst->precision < 0) ? i : tst->precision);
	if (tst->op_mns)
		type_s_l_op_mns(tst, i, c);
	else
		type_s_l_op(tst, i, c);
}
