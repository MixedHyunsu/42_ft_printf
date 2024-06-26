/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:57:01 by hyunski2          #+#    #+#             */
/*   Updated: 2024/04/23 19:57:03 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		num_of_char;
	va_list	ap;

	num_of_char = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			num_of_char++;
		}
		else
		{
			format++;
			num_of_char += ft_specifier(format, ap);
			format++;
		}
	}
	va_end (ap);
	return (num_of_char);
}
