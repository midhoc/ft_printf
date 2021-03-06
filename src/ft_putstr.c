/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 21:15:06 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 03:20:03 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	int i;

	if (str)
	{
		i = 0;
		while (*(str + i) != '\0')
		{
			ft_putchar(*(str + i));
			i++;
		}
	}
}
