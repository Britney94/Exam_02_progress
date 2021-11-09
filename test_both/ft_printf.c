#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_putnbr_hexa(unsigned long int nb)
{
	unsigned long int	rest;
	unsigned long int	result;
	static int		time;

	result = nb;
	if (time == 0 && nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (result != 0)
	{
		rest = result % 16;
		time++;
		ft_putnbr_hexa(result / 16);
	}
	time-- && result != 0;
	if (time < 7 && result != 0)
	{
		if (rest < 10)
			ft_putchar(rest + 48);
		else if (rest >= 10)
			ft_putchar(rest - 10 + 97);
	}
}

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list 		va;
	int			my_arg_d;
	unsigned int		my_arg_x;
	char			*my_arg_s;

	i = 0;
	va_start(va, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == 'd')
		{
			my_arg_d = va_arg(va, int);
			ft_putnbr(my_arg_d);
			i = i + 2;
		}
		if (s[i] == '%' && s[i + 1] == 's')
		{
			my_arg_s = va_arg(va, char *);
			ft_putstr(my_arg_s);
			i = i + 2;
		}
		if (s[i] == '%' && s[i + 1] == 'x')
		{
			my_arg_x = va_arg(va, unsigned int);
			ft_putnbr_hexa(my_arg_x);
			i = i + 2;
		}
		ft_putchar(s[i]);
		i++;
	}
	va_end(va);
	return (0);
}

int	main(int ac, char **av)
{
	int	nb;

	nb = atoi(av[1]);
	printf("OG = >>%d<< || >>%s<< || >>%x<<\n", nb, av[2], nb);
	ft_printf("MY = >>%d<< || >>%s<< || >>%x<<\n", nb, av[2], nb);
}


