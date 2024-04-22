
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
//	int		i;
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
