/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:08:36 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:18:16 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width_precision(char **str, t_ft_printf *tst)
{
	if (ft_isdigit(**str))
	{
		tst->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else if (**str == '.')
	{
		(*str)++;
		if ((tst->precision = ft_atoi(*str)) < 0)
			tst->precision = 0;
		while (ft_isdigit(**str))
			(*str)++;
	}
	else
		return (0);
	return (1);
}

int		get_option(char **str, t_ft_printf *tst)
{
	if (**str == '+')
		tst->op_pls = 1;
	else if (**str == '-')
		tst->op_mns = 1;
	else if (**str == ' ')
		tst->op_sp = 1;
	else if (**str == '#')
		tst->op_htg = 1;
	else if (**str == '0')
		tst->op_0 = 1;
	else
		return (0);
	(*str)++;
	return (1);
}

int		get_lengths(char **str, t_ft_printf *tst)
{
	char	*s;
	char	*c;
	int		tmp;

	s = "hljztL";
	c = ft_strchr(s, **str);
	if (!c || !*c)
		return (0);
	if (**str == 'h' && *((*str) + 1) == 'h')
	{
		tmp = HH;
		(*str) += 2;
	}
	else if (**str == 'l' && *((*str) + 1) == 'l')
	{
		tmp = LL;
		(*str) += 2;
	}
	else
	{
		tmp = (c - s);
		(*str)++;
	}
	tst->length = ((tst->length < tmp) ? tmp : tst->length);
	return (1);
}

int		get_type(char **str, t_ft_printf *tst)
{
	char	*s;
	char	*c;

	s = "diouxXcspf%OU";
	c = ft_strchr(s, **str);
	if (!c || !*c)
		return (0);
	tst->type = (c - s);
	(*str)++;
	return (1);
}

int		get_format(char **str, t_ft_printf *tst)
{
	(*str)++;
	while (get_option(str, tst)
			|| get_width_precision(str, tst)
			|| get_lengths(str, tst))
	{
	}
	return (get_type(str, tst));
}
