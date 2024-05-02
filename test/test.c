#include "../src/ft_printf.h"

#include <stdio.h>

int	main(){
	int		len;
	int		len2;
	char	*a = "Hello";

	len = ft_printf("ft_printf = %p %x\n", a, 0);
	len2 = printf("printf = %p %x\n", a, 0);
	printf("\nlen of ft_printf: %d\n", len);
	printf("len of printf: %d\n", len2);
}