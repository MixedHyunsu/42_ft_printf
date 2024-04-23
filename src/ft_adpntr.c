
#include "ft_printf.h"

static void	ft_statichexa(unsigned long x)
{
	if (x >= 16)
	{
		ft_statichexa(x / 16);
		ft_statichexa(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar((x + '0'));
		else
			ft_putchar((x + 'a' - 10));
	}
}

static int ft_nbrlen(unsigned long x)
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

int	ft_adpntr(unsigned long p)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	ft_statichexa(p);
	len += ft_nbrlen(p);
	return (len);
}
