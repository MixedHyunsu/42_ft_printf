/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:29:57 by hyunski2          #+#    #+#             */
/*   Updated: 2024/03/16 13:29:59 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	lenofn(int n)
{
	int	len;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	if (n < 10)
		len = 1;
	else
		len = lenofn(n / 10) + 1;
	return (len);
}

static void	*setup(char *str, int n, int len)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	while (i + sign < len)
	{
		str--;
		*str = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (sign == 1)
		*--str = '-';
	str[len] = '\0';
	return (str);
}

static void	*ismin(char *str, int n, int len)
{
	int	i;

	i = 0;
	str[10] = '8';
	n = 214748364;
	while (i < len)
	{
		str[len - i - 1] = n % 10 + '0';
		n /= 10;
		i ++;
	}
	str[0] = '-';
	str[len + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 0;
	len = lenofn(n);
	if (n < 0)
		sign = 1;
	str = (char *)malloc(sizeof(char) * len + 1 + sign);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str = ismin(str, n, len);
		return (str);
	}
	str = setup(&str[len + sign], n, sign + len);
	return (str);
}

