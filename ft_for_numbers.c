#include "ft_printf.h"

static int	convert_to_int(int n)
{
	char	c;

	c = '0'; // esse char recebe o valor do zero na tabela ASCII
	c = c + n; // o zero é adicionado ao int n passado, assim passamos a ter um char com o mesmo valor desse n
	write (1, &c, 1); //no descritor passado,  colocamos o conteúdo de c
	return (1); // retornamos 1, pois é a quantidade de caracter impresso a cada chamada
}

int ft_putnbr(int n)
{   
	int len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	else if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	else if (n <= 9)
	{
		if (convert_to_int(n + 48))
			len += ft_putchar(n + 48);
	}
	else
	{
		len += ft_putnbr(d / 10);
		len += ft_putchar((d % 10) + 48);
	}
	return (len);
}

// FALTA FT_PUTUNBR
//       FT_PUTPTR;
//        FT_PUTHEXA;