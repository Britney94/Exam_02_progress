#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

int	itohexa(unsigned long int n)
{
	unsigned long int	rest;
	unsigned long int	result;
	static int		time;

	result = n;
	if (time == 0 && n == 0)
	{
		ft_putchar('0');
		return (0);
	}
	if (result != 0)
	{
		time++;
		rest = result % 16;
//		result = result / 16;
		itohexa(result / 16);
	}
	time--;
//	printf("\t|| time = %d\n", time);
	if (time < 7)
	{	
		if (rest >= 10 && result != 0)
			ft_putchar(rest - 10 + 97);
		else if (rest < 10 && result != 0)
			ft_putchar(rest + 48);
	}
	return (0);
}
		
int	ft_printf(char *s, ...)
{
	int	i;
	va_list	va;
	unsigned int	my_arg_x;
	int		my_arg_d;
	char		*my_arg_s;

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
			itohexa(my_arg_x);
			i = i + 2;
		}
		ft_putchar(s[i++]);
	}
	va_end(va);
	return (1);
}

int	main(int ac, char **av)
{
	int	n;

	n = atoi(av[1]);
//	ft_putnbr(n);
//	write(1, "\nMY printf >>>", 14);
//	itohexa(n);
//	write(1, "<<<", 3);
	ft_printf("\nMY printf >>>%d||%x||%s<<<\n", n, n, av[2]);
	printf("\nOG printf >>>%d||%x||%s<<<\n", n, n, av[2]);
}
