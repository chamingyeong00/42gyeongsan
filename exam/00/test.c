#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*void	ft_put_string(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}*/

void	ft_put_number(int nbr)
{
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -nbr;
	}
	else
		n = nbr;
	if (n >= 10)
	{
		ft_put_number(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

int	main(void)
{
	ft_put_number(2147483647);
}
