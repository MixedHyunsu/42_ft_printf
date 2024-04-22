#ifndef	LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);
int		ft_decimal(int	d);
int		ft_unsignedint(unsigned int u);
int		ft_string(char *s);
int		ft_charactor(int c);
int		ft_percent(void);
int		ft_hexa(unsigned int x, const char *format);
int		ft_adpntr(unsigned long p);
int		ft_specifier(const char *format, va_list args);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif