#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h> // va_start, va_arg, va_copy, va_end
#include <unistd.h> // write
#include <stdlib.h> // malloc

//abaixo, declaro as funções que irei utilizar

int         ft_printf(const char *format, ...);
static int	ft_checking_format(char *format, va_list args, int i);
static int	ft_priting(char *format, va_list args);
int         ft_putnbr(int n);
int         ft_putstr(char *s);


#endif 