/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:56:37 by hyunski2          #+#    #+#             */
/*   Updated: 2024/04/23 19:56:38 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int x)
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

static void	ft_printhexa(unsigned int x, const char Xx)
{
	if (x >= 16)
	{
		ft_printhexa(x / 16, Xx);
		ft_printhexa(x % 16, Xx);
	}
	else
	{
		if (x <= 9)
			ft_putchar((x + '0'));
		else if (Xx == 'x')
			ft_putchar((x + 'a' - 10));
		else if (Xx == 'X')
			ft_putchar((x + 'A' - 10));
	}
}

int	ft_hexa(unsigned long x, const char *format)
{
	int		len;
	char	xx;

	len = ft_nbrlen(x);
	xx = *format;
	ft_printhexa(x, xx);
	return (len);
}
