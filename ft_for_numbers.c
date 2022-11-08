/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:08:05 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/11/08 22:55:45 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-", 1);
		len += write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		n += 48;
		len += write(1, &n, 1);
	}
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_puthexa(unsigned int x, int signal)
{
	char	*base_char;
	int		i;

	i = 0;
	if (signal == 0)
		base_char = "0123456789abcdef";
	else
		base_char = "0123456789ABCDEF";
	if (x < 16)
		return (ft_putchar(base_char[x]));
	i += ft_puthexa(x / 16, signal);
	i += ft_putchar(base_char[x % 16]);
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	char	*base_char;
	int		i;

	i = 0;
	base_char = "0123456789abcdef";
	if (!ptr)
		return (ft_putstr(SYS_NIL));
	if (ptr < 16)
	{
		i += ft_putstr("0x"); //
		i += ft_putchar(base_char[ptr]);
		return (i);
	}
	i += ft_putptr(ptr / 16);
	i += ft_putchar(base_char[ptr % 16]);
	return (i);
}
