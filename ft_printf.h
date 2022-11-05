#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h> // va_start, va_arg, va_copy, va_end
#include <unistd.h> // write
#include <stdlib.h> // malloc

//abaixo, declaro as funções que irei utilizar

int ft_printf(const char *format, ...);

#endif 