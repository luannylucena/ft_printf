/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:14:14 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/11/09 19:24:07 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checking_format(const char *format, va_list args, int i)
{
	int	len_format;

	len_format = 0;
	if (format[i] == 'i' || format[i] == 'd')
		len_format = ft_putnbr(va_arg(args, int));
	else if (format[i] == 'c')
		len_format = ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		len_format = ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		len_format = ft_putptr(va_arg(args, unsigned long));
	else if (format[i] == 'u')
		len_format = ft_putunbr(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		len_format = ft_puthexa(va_arg(args, unsigned int), 0);
	else if (format[i] == 'X')
		len_format = ft_puthexa(va_arg(args, unsigned int), 1);
	else if (format[i] == '%')
		len_format = ft_putchar('%');
	return (len_format);
}

static int	ft_priting(const char *format, va_list args)
{
	int	i;
	int	len_str;

	i = 0;
	len_str = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len_str += ft_checking_format(format, args, i);
		}
		else
			len_str += write(1, &format[i], 1);
		i++;
	}
	return (len_str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len_printed;

	if (!format)
		return (-1);

	va_start(args, format);
	len_printed = ft_priting(format, args);
	va_end(args);
	return (len_printed);
}
