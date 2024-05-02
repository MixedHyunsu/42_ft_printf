/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:02:24 by hyunski2          #+#    #+#             */
/*   Updated: 2024/04/23 20:02:25 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(const char *format, va_list ap)
{
	int	len;

	len = 0;
	if (*format == 'd' || *format == 'i')
		len += ft_decimal(va_arg(ap, int));
	else if (*format == 'u')
		len += ft_unsignedint(va_arg(ap, unsigned int));
	else if (*format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (*format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (*format == '%')
		len += ft_percent();
	else if (*format == 'x' || *format == 'X')
		len += ft_hexa(va_arg(ap, unsigned int), format);
	else if (*format == 'p')
		len += ft_adpntr(va_arg(ap, unsigned long));
	return (len);
}
