/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 03:18:24 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 03:22:07 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_buf(char const *str, t_ft_printf *tst)
{
	int i;

	if (str)
	{
		i = 0;
		while (*(str + i) != '\0')
		{
			ft_putchar_buff(*(str + i), tst);
			i++;
		}
	}
}
