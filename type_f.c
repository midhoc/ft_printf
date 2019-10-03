/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 02:20:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:47:18 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		round_float(t_ft_printf *tst, long double *nbr)
{
	long double		tmp;
	int				i;
	long double		add;

	i = -1;
	add = 1.1;
	if (*nbr > ULLONG_MAX || *nbr < (double)-1 * ULLONG_MAX)
		*nbr = 0;
	if (*nbr < 0)
		tmp = *nbr * -1;
	else
		tmp = *nbr;
	while (++i <= tst->precision)
	{
		tmp -= (unsigned long long int)tmp;
		tmp *= 10;
		add /= 10;
	}
	if ((unsigned long long int)tmp % 10 > 5)
	{
		if (*nbr < 0)
			*nbr -= add;
		else
			*nbr += add;
	}
}

int			count_digit_f(t_ft_printf *tst, long double nbr)
{
	long int	counter;
	long double	nb;

	counter = 0;
	nb = 0;
	if (nbr < 0)
		nb = -1 * nbr;
	else if (nbr > 0)
		nb = nbr;
	while (nb >= 10)
	{
		nb /= 10;
		counter++;
	}
	if (tst->precision > 0)
		counter += 1 + tst->precision;
	return (counter + 1);
}

int			put_sign_f(t_ft_printf *tst, long double nbr, int flag)
{
	if (flag && (nbr < 0 || tst->op_pls || tst->op_sp))
		return (1);
	if (nbr < 0)
		ft_putchar_buff('-', tst);
	else if (tst->op_pls)
		ft_putchar_buff('+', tst);
	else if (tst->op_sp)
		ft_putchar_buff(' ', tst);
	else
		return (0);
	return (1);
}

void		type_f(t_ft_printf *tst, va_list argv)
{
	long double c;

	if (tst->precision < 0)
		tst->precision = 6;
	if (tst->length == L_)
		c = va_arg(argv, long double);
	else
		c = va_arg(argv, double);
	put_f(tst, c);
}
