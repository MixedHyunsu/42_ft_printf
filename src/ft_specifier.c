#include "libftprintf.h"

int	ft_specifier(const char *format, va_list ap)
{
	int	len;

	len = 0;
	if (*format == 'd' || *format == 'i')
		len += ft_decimal(va_arg(ap, int));
	else if (*format == 'u')
		len += ft_unsignedint(va_arg(ap, unsigned int));
	else if (*format == 's')
		len += ft_string(va_arg(ap, char *));
	else if (*format == 'c')
		len += ft_charactor(va_arg(ap, int));
	else if (*format == '%')
		len += ft_percent();
	else if (*format == 'x' || *format == 'X')
		len += ft_hexa(va_arg(ap, unsigned int), format);
	else if (*format == 'p')
		len += ft_adpntr(va_arg(ap, unsigned long));
	return (len);
}

