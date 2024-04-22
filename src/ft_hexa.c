
#include "libftprintf.h"

static int ft_nbrlen(unsigned int x)
{
	int	len;

	len = 0;
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

int	ft_hexa(unsigned int x, const char *format)
{
	int		len;
	char	Xx;

	len = ft_nbrlen(x);
	Xx = *format;
	ft_printhexa(x, Xx);
	return (len);
}