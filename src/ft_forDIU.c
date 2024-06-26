/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forDIU.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:56:22 by hyunski2          #+#    #+#             */
/*   Updated: 2024/04/23 19:56:24 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_decimal(int d)
{
	int		len;

	ft_putnbr(d);
	len = ft_nbrlen(d);
	return (len);
}

int	ft_unsignedint(unsigned int u)
{
	int		len;

	ft_putnbr(u);
	len = ft_nbrlen(u);
	return (len);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
