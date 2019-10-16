/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_buf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 03:21:28 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/01 05:25:53 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_buf(unsigned long long int nb, t_ft_printf *tst)
{
	unsigned long long int				counter;

	counter = 1;
	while (nb / counter > 9)
	{
		counter *= 10;
	}
	while (counter >= 1)
	{
		ft_putchar_buff('0' + nb / counter, tst);
		nb = nb - (nb / counter) * counter;
		counter /= 10;
	}
}
