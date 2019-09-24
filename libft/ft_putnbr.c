/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:39:29 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/23 19:39:56 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int nbr)
{
	long int				counter;
	unsigned long long int	nb;

	counter = 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -1 * nbr;
	}
	else
		nb = nbr;
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
