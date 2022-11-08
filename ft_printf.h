/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:09:19 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/11/08 23:14:58 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <unistd.h> 
# include <stdlib.h> 

# define SYS_NIL "(nil)"

int			ft_printf(const char *format, ...);
int			ft_putnbr(int n);
int			ft_putstr(char *s);
int			ft_putchar(char c);
int			ft_putunbr(unsigned int u);
int			ft_puthexa(unsigned int x, int signal);
int			ft_putptr(unsigned long ptr);

#endif 