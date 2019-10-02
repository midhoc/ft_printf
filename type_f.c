/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 02:20:42 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/02 05:00:25 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			round_float(t_ft_printf *tst, long double *nbr)
{
	long double		tmp;
	int				i;
	long double		add;

	i = -1;
	add = 1;
	if(*nbr < 0)
		tmp = *nbr * -1;
	else
		tmp = *nbr;
	while (++i < tst->precision)
	{
		tmp -= (unsigned long long int)tmp;
		tmp *= 10;
		add /= 10;
	}
	if ((long long int)tmp  % 10 > 5)
	{
		if(*nbr < 0)
			*nbr -= add;
		else
			*nbr += add;
	}
}

int				count_digit_f(t_ft_printf *tst, long double nbr)
{
	long int	counter;
	long double	nb;

	counter = 0;
	nb = 0;
	if (nbr < 0)
		nb = -1 * nbr;
	else if (nbr > 0)
		nb = nbr;
	// else if (nbr == 0 && tst->precision == 0)
	//  	return (0);
	while (nb > 9)
	{
		nb /= 10;
		counter++;
	}
	if (tst->precision > 0)
		counter += 1 + tst->precision;
	return (counter + 1);
}

static int	put_sign(t_ft_printf *tst, long double nbr, int flag)
{
	if (flag && (nbr < 0 || tst->op_pls || tst->op_sp))
		return(1);
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
char		*ftoa(long double nbr, int c, t_ft_printf *tst)
{
	char		*str;
	char		*str_itoa;
	int			i;
	long double	nb;

	i = -1;
	if(!(str = (char *)malloc(c * sizeof(char) + 1)))
		return (NULL);
	str[c] = '\0';
	if (nbr < 0)
		nb = -1 * nbr;
	else
		nb = nbr;
	str_itoa = ft_itoa_base((unsigned long long int)nb, 10 , 0);
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
static void	put_f(t_ft_printf *tst, long double nbr)
{
	int		c;
	char	*str;

	round_float(tst, &nbr);
	c = count_digit_f(tst, nbr);
	str = ftoa(nbr, c, tst);
	if (tst->op_mns)
	{
		tst->width -= (put_sign(tst, nbr, 0) + ft_max(c, tst->precision));
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		ft_putstr_buf(str, tst);
		while (tst->width-- > 0)
			ft_putchar_buff(' ', tst);
	}
	else if (tst->op_0)
	{
		if (tst->precision >= 0)
		{
			tst->width -= (put_sign(tst, nbr, !tst->op_0) + ft_max(c, tst->precision));
			while (tst->width-- >0)
				ft_putchar_buff(' ', tst);
		}
		else
			tst->precision = tst->width - put_sign(tst, nbr, !tst->op_0);
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		ft_putstr_buf(str, tst);
	}
	else
	{
		tst->width -= (put_sign(tst, nbr, 1) + ft_max(c, tst->precision));
		while (tst->width-- >0)
			ft_putchar_buff(' ', tst);
		put_sign(tst, nbr, 0);
		while (c++ < tst->precision)
			ft_putchar_buff('0', tst);
		ft_putstr_buf(str, tst);
	}
	free(str);
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
