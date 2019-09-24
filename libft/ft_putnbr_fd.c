/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 22:25:04 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/22 20:29:38 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long int nbr, int fd)
{
	long int				counter;
	unsigned long long int	nb;

	counter = 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd('0' + nb / counter, fd);
		nb = nb - (nb / counter) * counter;
		counter /= 10;
	}
}
