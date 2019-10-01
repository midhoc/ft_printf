/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:53:00 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 03:57:36 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_sign(t_ft_printf *tst,unsigned long long int nbr, int flag, int flag_up)
{
	if (flag && ((tst->op_htg && nbr) || flag_up == 3))
		return (2);
	if (flag_up == 3)
	{
		ft_putchar_buff('0', tst);
		ft_putchar_buff('x', tst);
		return (2);
	}
	if (tst->op_htg && nbr)
	{
		if (flag_up)
		{
			ft_putchar_buff('0', tst);
			ft_putchar_buff('X', tst);
		}
		else
		{
			ft_putchar_buff('0', tst);
			ft_putchar_buff('x', tst);
		}
		return (2);
	}
	return (0);
}

static void			put_x_op_mns(t_ft_printf *tst, char *str, int c, int flag_up, unsigned long long int nbr)
{
	tst->width -= (put_sign(tst, nbr, 0, flag_up) + ft_max(c, tst->precision));
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr > 0)
		ft_putstr_buf(str, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
	while (tst->width-- > 0)
		ft_putchar_buff(' ', tst);
}

static void			put_x_op_0(t_ft_printf *tst, char *str, int c, int flag_up, unsigned long long int nbr)
{
	if (tst->precision >= 0)
	{
		tst->width -= (put_sign(tst, nbr, !tst->op_0, flag_up) + ft_max(c, tst->precision));
		while (tst->width-- >0)
			ft_putchar_buff(' ', tst);
	}
	else
		tst->precision = tst->width - put_sign(tst, nbr, !tst->op_0, flag_up);
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr > 0)
		ft_putstr_buf(str, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
}

static void		put_x_op_(t_ft_printf *tst, char *str, int c, int flag_up, unsigned long long int nbr)
{
	tst->width -= (put_sign(tst, nbr, 1, flag_up) + ft_max(c, tst->precision));
	while (tst->width-- >0)
		ft_putchar_buff(' ', tst);
	put_sign(tst, nbr, 0, flag_up);
	while (c++ < tst->precision)
		ft_putchar_buff('0', tst);
	if (nbr > 0)
		ft_putstr_buf(str, tst);
	else if (tst->precision)
		ft_putchar_buff('0', tst);
}

void			put_x(t_ft_printf *tst, unsigned long long int nbr, int flag_up)
{
	int		c;
	int		i;
	char	*str;

	i = 0;
	if(!(str = ft_itoa_base(nbr, 16, flag_up)))
		return;
	if (nbr == 0 && tst->precision == 0)
		c = 0;
	else
		c = ft_strlen(str);
	if (tst->op_mns)
		put_x_op_mns(tst, str, c, flag_up, nbr);
	else if (tst->op_0)
		put_x_op_0(tst, str, c, flag_up, nbr);
	else
		put_x_op_(tst, str, c, flag_up, nbr);
	free(str);
}
