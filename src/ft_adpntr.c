/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adpntr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:56:11 by hyunski2          #+#    #+#             */
/*   Updated: 2024/04/23 19:56:14 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_statichexa(unsigned long x)
{
	if (x >= 16)
	{
		ft_statichexa(x / 16);
		ft_statichexa(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar((x + '0'));
		else
			ft_putchar((x + 'a' - 10));
	}
}

static int	ft_nbrlen(unsigned long x)
{
	int	len;

	len = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

int	ft_adpntr(unsigned long p)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	ft_statichexa(p);
	len += ft_nbrlen(p);
	return (len);
}
