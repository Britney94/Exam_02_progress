

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
{
	int	sign;
	int	result;
	int	rest;

	sign = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + 48);
}

void	ft_putnbr_hexa(int nb)
{
	int	result;
	int	rest;
	
	result = nb;
	if (result >= 10)
	{
		rest = result % 16;
		ft_putnbr_hexa(result / 16);
	}
	if (result != 0)
	{
		if (rest < 10)
			ft_putchar(rest + 48);
		else if (rest >= 10)
			ft_putchar(rest - 10 + 97);
	}
}

int	ft_printf(char *str, ...)
{
	va_list va;
	int	i;
	char	*arg_str;
	int	arg_int;
	unsigned int	arg_hexa;	

	va_start(va, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i++]);
		else
		{
			if (str[i + 1] && str[i + 1] == 's')
			{
				arg_str = va_arg(va, char *);
				ft_putstr(arg_str);
			}
			if (str[i + 1] && str[i + 1] == 'd')
			{
				arg_int = va_arg(va, int);
				ft_putnbr(arg_int);
			}
			if (str[i + 1] && str[i + 1] == 'x')
			{
				arg_hexa = va_arg(va, long);
				ft_putnbr_hexa(arg_hexa);
			}
			i = i + 2;
		}
	}
	va_end(va);
	return (i);
}

int	main(int ac, char **av)
{
	int	nb;

	nb = atoi(av[1]);
	printf("OG = >>%d<< || >>%s<< || >>%x<<\n", nb, av[2], nb);
	ft_printf("MY = >>%d<< || >>%s<< || >>%x<<\n", nb, av[2], nb);
}
