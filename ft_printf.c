// O objetivo deste projeto é escrver uma biblioteca que contenha 'ft_printf(), que imite o comportamento da função 'printf' original, que aceita uma número variável de argumentos. 

/

// Iremos analisar "c,s,p,d,i,u,x,X, e %"

#include "ft_printf.h"

// A função analisará o tipo de caracter logo após o '%' e vai chamar a função adequada para a impressão deste na tela. A função retornará o número de caracteres que foram impressos na tela. 

static int	ft_checking_format(char *format, va_list args, int i)
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
	// else if (format[i] == 'x' || format[i] == 'X')
		//len_format = (FAZER A FUNÇÃO)
	else if (format[i] == '%')
		len_format = ft_putchar('%');
	return (len_format);
}

static int	ft_priting(char *format, va_list args)
{
	int i; // percorrerá a string
	int	len_str; // tamanho da string impressa

	i = 0;
	len_str = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len_str += ft_cheking_format(format, args, i);
		}
		else
			len_str += write(1, &format[i], 1);
		i++; //avança para a próxima casa da string
	}
	return(len_str);
}

int	ft_printf(const char *format, ...)
{
	va_list args;

	int	len_printed;

	va_start(args, format); //(list, último parâmetro)

	len_printed = ft_priting(format, args);

	va_end(args);

	return (len_printed);
}
