/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunski2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:57:41 by hyunski2          #+#    #+#             */
/*   Updated: 2024/04/23 19:57:43 by hyunski2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr(long n);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_printf(const char *format, ...);
int		ft_decimal(int d);
int		ft_unsignedint(unsigned int u);
int		ft_percent(void);
int		ft_hexa(unsigned long x, const char *format);
int		ft_adpntr(unsigned long p);
int		ft_specifier(const char *format, va_list args);

#endif
