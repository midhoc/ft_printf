/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:13:02 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:41:38 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type_o_hh(t_ft_printf *tst, va_list argv)
{
	unsigned int c;

	c = va_arg(argv, unsigned int);
	if (tst->length == HH)
		put_o(tst, (unsigned char)c);
	else
		put_o(tst, (unsigned short int)c);
}

static void	type_o_ll(t_ft_printf *tst, va_list argv)
{
	unsigned long long int c;

	c = va_arg(argv, unsigned long long int);
	put_o(tst, c);
}

static void	type_o_l(t_ft_printf *tst, va_list argv)
{
	unsigned long int c;

	c = va_arg(argv, unsigned long int);
	put_o(tst, c);
}

static void	type_o_z(t_ft_printf *tst, va_list argv)
{
	size_t c;

	c = va_arg(argv, size_t);
	put_o(tst, c);
}

void		type_o(t_ft_printf *tst, va_list argv)
{
	unsigned int	c;

	if (tst->length == HH || tst->length == H)
		type_o_hh(tst, argv);
	else if (tst->length == LL)
		type_o_ll(tst, argv);
	else if (tst->length == L)
		type_o_l(tst, argv);
	else if (tst->length == J)
		put_o(tst, va_arg(argv, uintmax_t));
	else if (tst->length == Z)
		type_o_z(tst, argv);
	else
	{
		c = va_arg(argv, unsigned int);
		put_o(tst, c);
	}
}
