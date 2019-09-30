/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:18:35 by sshin             #+#    #+#             */
/*   Updated: 2019/09/30 02:38:07 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(unsigned long long int num, int flag_up)
{
	if (num >= 10)
	{
		if (flag_up)
			return (num - 10 + 'A');
		return (num - 10 + 'a');
	}
	else
		return (num + '0');
}

char		*ft_itoa_base(unsigned long long int value, int base, int flag_up)
{
	int						i;
	char					*str;
	unsigned long long int	temp;

	i = 0;
	temp = value;
	while (temp >= (unsigned long long int)base)
	{
		temp = temp / base;
		i++;
	}

	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		temp = value % base;
		str[i] = ft_convert(temp, flag_up);
		value = value / base;
		i--;
	}
	return (str);
}
