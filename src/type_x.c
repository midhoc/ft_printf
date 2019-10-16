/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:40:16 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:38:18 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type_x_hh(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned int c;

	c = va_arg(argv, unsigned int);
	if (tst->length == HH)
		put_x(tst, (unsigned char)c, flag_up);
	else
		put_x(tst, (unsigned short int)c, flag_up);
}

static void	type_x_ll(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned long long int c;

	c = va_arg(argv, unsigned long long int);
	put_x(tst, c, flag_up);
}

static void	type_x_l(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_x(tst, c, flag_up);
}

static void	type_p(t_ft_printf *tst, va_list argv)
{
	unsigned long long int c;

	c = (unsigned long long int)va_arg(argv, void*);
	put_x(tst, c, 3);
}

void		type_x(t_ft_printf *tst, va_list argv, int flag_up)
{
	unsigned int	c;

	if (tst->type == 8)
		type_p(tst, argv);
	else if (tst->length == HH || tst->length == H)
		type_x_hh(tst, argv, flag_up);
	else if (tst->length == LL)
		type_x_ll(tst, argv, flag_up);
	else if (tst->length == L)
		type_x_l(tst, argv, flag_up);
	else if (tst->length == J)
		put_x(tst, va_arg(argv, uintmax_t), flag_up);
	else if (tst->length == Z)
		put_x(tst, va_arg(argv, size_t), flag_up);
	else
	{
		c = va_arg(argv, unsigned int);
		put_x(tst, c, flag_up);
	}
}
