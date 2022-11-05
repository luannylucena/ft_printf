int ft_putnbr(int n)
{   
	if (n == -2147483648)
	{
		ft_putchar_fd('-');
		ft_putchar_fd('2');
		ft_putnbr_fd(147483648);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr_fd(n * -1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10); 
	}
	else
		ft_putchar_fd(n + '0');
}

// FALTA FT_PUTUNBR
//       FT_PUTPTR;
//        FT_PUTHEXA;