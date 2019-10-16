/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 03:59:49 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:40:37 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type_u_hh(t_ft_printf *tst, va_list argv)
{
	int c;

	c = va_arg(argv, int);
	if (tst->length == HH)
		put_u(tst, (unsigned char)c);
	else
		put_u(tst, (unsigned int)c);
}

static void	type_u_ll(t_ft_printf *tst, va_list argv)
{
	unsigned long long int c;

	c = va_arg(argv, unsigned long long int);
	put_u(tst, c);
}

static void	type_u_l(t_ft_printf *tst, va_list argv)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_u(tst, c);
}

static void	type_u_z(t_ft_printf *tst, va_list argv)
{
	size_t c;

	c = va_arg(argv, size_t);
	put_u(tst, c);
}

void		type_u(t_ft_printf *tst, va_list argv)
{
	unsigned int c;

	if (tst->type == 12)
		type_u_ll(tst, argv);
	else if (tst->length == HH || tst->length == H)
		type_u_hh(tst, argv);
	else if (tst->length == LL)
		type_u_ll(tst, argv);
	else if (tst->length == L)
		type_u_l(tst, argv);
	else if (tst->length == J)
		put_u(tst, va_arg(argv, uintmax_t));
	else if (tst->length == Z)
		type_u_z(tst, argv);
	else
	{
		c = va_arg(argv, unsigned int);
		put_u(tst, c);
	}
}
