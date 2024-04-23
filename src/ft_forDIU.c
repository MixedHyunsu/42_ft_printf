
#include "ft_printf.h"

#include <stdio.h>

int	ft_decimal(int	d)
{
	char	*number;
	int		len;
	
	number = ft_itoa(d);
	len = ft_putstr(number);
	free (number);
	return (len);
}

int	ft_unsignedint(unsigned int u)
{
	char	*number;
	int		len;

	number = ft_uitoa(u);
	len = ft_putstr(number);
	free (number);
	return (len);
}

int	ft_string(char *s)
{
	int	len;

	len = ft_putstr(s);
	ft_putchar('\0');
	return (len);
}

int	ft_charactor(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}