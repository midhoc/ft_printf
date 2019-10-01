/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:54:23 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/30 20:58:33 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_sign(t_ft_printf *tst, int flag)
{
	if (flag && tst->op_htg)
		return (1);
	if (tst->op_htg)
	{
		write(1,"0", 1);
		return (1);
	}
	return (0);
}

static void		put_x_op_mns(t_ft_printf *tst, char *str, int c, unsigned long long int nbr)
{
	tst->width -= (put_sign(tst, 0) + ft_max(c, tst->precision));
	while (c++ < tst->precision)
		write(1, "0", 1);
	if (nbr > 0)
		ft_putstr(str);
	else if (tst->precision)
		write(1, "0", 1);
	while (tst->width-- > 0)
		write(1, " ", 1);
}

static void		put_x_op_0(t_ft_printf *tst, char *str, int c, unsigned long long int nbr)
{
	if (tst->precision >= 0)
	{
		tst->width -= (put_sign(tst, !tst->op_0) + ft_max(c, tst->precision));
		while (tst->width-- >0)
			write(1, " ", 1);
	}
	else
		tst->precision = tst->width - put_sign(tst, !tst->op_0);
	while (c++ < tst->precision)
		write(1, "0", 1);
	if (nbr > 0)
		ft_putstr(str);
	else if (tst->precision)
		write(1, "0", 1);
}

static void		put_x_op_(t_ft_printf *tst, char *str, int c, unsigned long long int nbr)
{
	tst->width -= (put_sign(tst, 1) + ft_max(c, tst->precision));
	while (tst->width-- >0)
		write(1, " ", 1);
	put_sign(tst, 0);
	while (c++ < tst->precision)
		write(1, "0", 1);
	if (nbr > 0)
		ft_putstr(str);
	else if (tst->precision)
		write(1, "0", 1);
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
	if (tst->op_mns)
		put_x_op_mns(tst, str, c, nbr);
	else if (tst->op_0)
		put_x_op_0(tst, str, c, nbr);
	else
		put_x_op_(tst, str, c, nbr);
	free(str);
}
