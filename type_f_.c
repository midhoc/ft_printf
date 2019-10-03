/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 02:43:07 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:48:13 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ftoa(long double nbr, int c, t_ft_printf *tst)
{
	char		*str;
	char		*str_itoa;
	int			i;
	long double	nb;

	i = -1;
	if (!(str = (char *)malloc(c * sizeof(char) + 1)))
		return (NULL);
	str[c] = '\0';
	nb = (nbr < 0) ? (-1 * nbr) : nbr;
	str_itoa = ft_itoa_base((unsigned long long int)nb, 10, 0);
	ft_strcpy(str, str_itoa);
	free(str_itoa);
	nb -= (unsigned long long int)nb;
	if (tst->precision)
		str[c - tst->precision - 1] = '.';
	while (++i < tst->precision)
	{
		nb *= 10.0;
		str[c - tst->precision + i] = '0' + (unsigned long long int)nb;
		nb -= (unsigned long long int)nb;
	}
	str[c - tst->precision + i] = '\0';
	return (str);
}

static void	put_f_op_mns(t_ft_printf *tst, long double nbr, char *str, int c)
{
	tst->width -= (put_sign_f(tst, nbr, 0) + ft_max(c, tst->precision));
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	ft_putstr_buf(str, tst);
	while (tst->width-- > 0)
		ft_putchar_buff(' ', tst);
}

static void	put_f_op_0(t_ft_printf *tst, long double nbr, char *str, int c)
{
	if (tst->precision >= 0)
	{
		tst->width -= (put_sign_f(tst, nbr, !tst->op_0)
			+ ft_max(c, tst->precision));
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
	}
	else
		tst->precision = tst->width - put_sign_f(tst, nbr, !tst->op_0);
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	ft_putstr_buf(str, tst);
}

void		put_f(t_ft_printf *tst, long double nbr)
{
	int		c;
	char	*str;

	round_float(tst, &nbr);
	c = count_digit_f(tst, nbr);
	str = ftoa(nbr, c, tst);
	if (tst->op_mns)
		put_f_op_mns(tst, nbr, str, c);
	else if (tst->op_0)
		put_f_op_0(tst, nbr, str, c);
	else
	{
		tst->width -= (put_sign_f(tst, nbr, 1) + ft_max(c, tst->precision));
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
		put_sign_f(tst, nbr, 0);
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		ft_putstr_buf(str, tst);
	}
	free(str);
}
