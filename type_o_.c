/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:54:23 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 06:14:34 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_sign(t_ft_printf *tst, unsigned long long int nbr, int flag)
{
	if (flag && tst->op_htg && nbr)
		return (1);
	if (tst->op_htg && nbr)
	{
		ft_putchar_buff('0', tst);
		return (1);
	}
	return (0);
}

static void		put_x_op_mns(t_ft_printf *tst, char *str, int c, unsigned long long int nbr)
{
	tst->width -= (put_sign(tst, nbr, 0) + ft_max(c, tst->precision));
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr > 0)
		ft_putstr_buf(str, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
	while (tst->width-- > 0)
		ft_putchar_buff(' ', tst);
}

static void		put_x_op_0(t_ft_printf *tst, char *str, int c, unsigned long long int nbr)
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
	if (nbr > 0)
		ft_putstr_buf(str, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
}

static void		put_x_op_(t_ft_printf *tst, char *str, int c, unsigned long long int nbr)
{
	tst->width -= (put_sign(tst, nbr, 1) + ft_max(c, tst->precision));
	while (tst->width-- >0)
		ft_putchar_buff(' ', tst);
	put_sign(tst, nbr, 0);
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr > 0)
		ft_putstr_buf(str, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
}

void			put_o(t_ft_printf *tst, unsigned long long int nbr)
{
	int		c;
	int		i;
	char	*str;

	i = 0;
	if(!(str = ft_itoa_base(nbr, 8, 0)))
		return;
	if (nbr == 0 && tst->precision == 0)
		c = 0;
	else
		c = ft_strlen(str);
	if (tst->op_htg )
		tst->precision--;
	if (tst->op_mns)
		put_x_op_mns(tst, str, c, nbr);
	else if (tst->op_0)
		put_x_op_0(tst, str, c, nbr);
	else
		put_x_op_(tst, str, c, nbr);
	free(str);
}
