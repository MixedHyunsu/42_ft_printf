
#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	len;
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;		
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}