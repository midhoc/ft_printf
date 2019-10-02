/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 02:50:01 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:04:53 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_ft_printf *tst)
{
	tst->op_mns = 0;
	tst->op_pls = 0;
	tst->op_0 = 0;
	tst->op_sp = 0;
	tst->op_htg = 0;
	tst->width = -1;
	tst->precision = -1;
	tst->length = -1;
	tst->type = -1;
}

void	init_buff(t_ft_printf *tst)
{
	ft_bzero(tst->buff, sizeof(tst->buff));
	tst->n_buff = 0;
	tst->length_buff = 0;
}

void	write_format(t_ft_printf *tst, va_list argv)
{
	if (tst->type == 0 || tst->type == 1)
		type_d(tst, argv);
	else if (tst->type == 3 || tst->type == 12)
		type_u(tst, argv);
	else if (tst->type == 7)
		type_s(tst, argv);
	else if (tst->type == 6)
		type_c(tst, argv);
	else if (tst->type == 10)
		type_per(tst);
	else if (tst->type == 9)
		type_f(tst, argv);
	else if (tst->type == 2 || tst->type == 11)
		type_o(tst, argv);
	else if (tst->type == 4 || tst->type == 8)
		type_x(tst, argv, 0);
	else if (tst->type == 5)
		type_x(tst, argv, 1);
}

int		ft_printf(const char *str, ...)
{
	va_list		argv;
	t_ft_printf	tst;
	int			c;

	c = 0;
	va_start(argv, str);
	init_buff(&tst);
	while (*str)
	{
		if (*str == '%')
		{
			init_struct(&tst);
			if (get_format((char **)&(str), &tst))
				write_format(&tst, argv);
		}
		else if (*str)
		{
			ft_putchar_buff(*str, &tst);
			str++;
		}
	}
	va_end(argv);
	ft_print_buff(&tst);
	return (1000 * tst.n_buff + tst.length_buff);
}
