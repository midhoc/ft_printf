/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 22:25:04 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/23 19:38:16 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned long long int nb)
{
	long int				counter;

	counter = 1;
	while (nb / counter > 9)
	{
		counter *= 10;
	}
	while (counter >= 1)
	{
		ft_putchar('0' + nb / counter);
		nb = nb - (nb / counter) * counter;
		counter /= 10;
	}
}
