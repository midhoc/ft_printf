/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 02:52:26 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 03:36:02 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_buff(char c, t_ft_printf *tst)
{
	if (tst->length_buff == 999)
	{
		ft_print_buff(tst);
		tst->length_buff = 0;
		tst->n_buff++;
	}
	tst->buff[tst->length_buff] = c;
	tst->length_buff++;
}

void	ft_print_buff(t_ft_printf *tst)
{
	write(1, tst->buff, tst->length_buff);
}
