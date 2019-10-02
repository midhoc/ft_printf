/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:25:19 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:40:20 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type_d_hh(t_ft_printf *tst, va_list argv)
{
	int c;

	c = va_arg(argv, int);
	if (tst->length == HH)
		put_d(tst, (signed char)c);
	else
		put_d(tst, (short int)c);
}

static void	type_d_ll(t_ft_printf *tst, va_list argv)
{
	long long int c;

	c = va_arg(argv, long long int);
	put_d(tst, c);
}

static void	type_d_l(t_ft_printf *tst, va_list argv)
{
	long int c;

	c = va_arg(argv, long int);
	put_d(tst, c);
}

static void	type_d_z(t_ft_printf *tst, va_list argv)
{
	size_t c;

	c = va_arg(argv, size_t);
	put_d(tst, c);
}

void		type_d(t_ft_printf *tst, va_list argv)
{
	int c;

	if (tst->length == HH || tst->length == H)
		type_d_hh(tst, argv);
	else if (tst->length == LL)
		type_d_ll(tst, argv);
	else if (tst->length == L)
		type_d_l(tst, argv);
	else if (tst->length == J)
		put_d(tst, va_arg(argv, intmax_t));
	else if (tst->length == Z)
		type_d_z(tst, argv);
	else
	{
		c = va_arg(argv, int);
		put_d(tst, c);
	}
}
