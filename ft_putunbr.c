/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:00 by sael-kha          #+#    #+#             */
/*   Updated: 2024/10/31 18:17:54 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_putunbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	printu(unsigned int nbr)
{
	int				count;
	unsigned int	nbr2;

	count = 0;
	ft_putunbr(nbr);
	nbr2 = nbr;
	count += (nbr2 == 0);
	while (nbr2)
	{
		nbr2 /= 10;
		count++;
	}
	return (count);
}
