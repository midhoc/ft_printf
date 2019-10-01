/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 03:25:03 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/30 20:56:09 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_c_(t_ft_printf *tst, va_list argv)
{
	char	c[2];

	c[0] = va_arg(argv, int);
	c[1] = '\0';
	if (!c[0])
		ft_putchar(0);
	tst->width--;
	if (tst->op_mns)
		type_s_op_mns(tst, 1, c);
	else
		type_s_op(tst, 1, c);
	return(1);
}

int		type_c_l(t_ft_printf *tst, va_list argv)
{
	wchar_t	c[2];

	c[0] = va_arg(argv, wchar_t);
	c[1] = '\0';
	if (!c[0])
		ft_putchar(0);
	tst->width--;
	if (tst->op_mns)
		type_s_l_op_mns(tst, 1, c);
	else
		type_s_l_op(tst, 1, c);
	return(1);
}

int		type_c(t_ft_printf *tst, va_list argv)
{
	// if (tst->precision >= 0)
		tst->precision = 1;
	if (tst->length == L)
		type_c_l(tst, argv);
	else
		type_c_(tst, argv);
	return(1);
}

int		type_per(t_ft_printf *tst)
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
	return(1);
}
