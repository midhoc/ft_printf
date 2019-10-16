/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 03:25:03 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:33:30 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_c_(t_ft_printf *tst, va_list argv)
{
	char	c[2];

	c[0] = va_arg(argv, int);
	c[1] = '\0';
	if (!c[0] && tst->op_mns)
		ft_putchar_buff(0, tst);
	tst->width--;
	if (tst->op_mns)
		type_s_op_mns(tst, 1, c);
	else
		type_s_op(tst, 1, c);
	if (!c[0] && !tst->op_mns)
		ft_putchar_buff(0, tst);
}

void	type_c_l(t_ft_printf *tst, va_list argv)
{
	wchar_t	c[2];

	c[0] = va_arg(argv, wchar_t);
	c[1] = '\0';
	if (!c[0])
		ft_putchar_buff(0, tst);
	tst->width--;
	if (tst->op_mns)
		type_s_l_op_mns(tst, 1, c);
	else
		type_s_l_op(tst, 1, c);
}

void	type_c(t_ft_printf *tst, va_list argv)
{
	tst->precision = 1;
	if (tst->length == L)
		type_c_l(tst, argv);
	else
		type_c_(tst, argv);
}

void	type_per(t_ft_printf *tst)
{
	char	c[2];

	c[0] = '%';
	c[1] = '\0';
	tst->precision = 1;
	tst->width--;
	if (tst->op_mns)
		type_s_op_mns(tst, 1, c);
	else
		type_s_op(tst, 1, c);
}
