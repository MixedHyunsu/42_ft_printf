#include "../src/libftprintf.h"

#include <stdio.h>

int	main(){
	int		len;
//	char	*a = "Hello";

	len = ft_printf("This charactor: %x\n", 12378);
	printf("\n%d", len);
}