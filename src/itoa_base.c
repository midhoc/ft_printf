/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:18:35 by sshin             #+#    #+#             */
/*   Updated: 2019/09/29 19:20:35 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_convert(unsigned long long int num)
{
	if (num >= 10)
		return (num - 10 + 'a');
	else 
		return (num + '0');
}

char	*itoa_base(unsigned long long int value, int base)
{
	int	i;
	char *str;
	unsigned long long int temp;

	i = 0;
	temp = value;
	while (temp >= base)
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
		str[i] = ft_convert(temp);
		value = value / base;
		i --;
	}
	return (str);
}
