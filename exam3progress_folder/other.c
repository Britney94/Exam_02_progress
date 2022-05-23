

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0)
	{
		ft_putchar('-');
		(*count)++;
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, count);
	ft_putchar(nb % 10 + 48);
	(*count)++;
}

void	ft_putnbr_hexa(unsigned long int nb, int *count)
{
	unsigned long int	result;
	unsigned long int	rest;
	static int time;

	result = nb;
	if (time == 0 && result == 0)
	{
		ft_putchar('0');
		(*count)++;
		return ;
	}
	if (result != 0)
	{
		rest = result % 16;
		time++;
		(*count)++;
		ft_putnbr_hexa(result / 16, count);
	}
	time--;
	if (result != 0 && time < 7 && rest >= 10)
	{
//		printf("[rest >= [%lu]]\n", rest);
		ft_putchar(rest - 10 + 97); 
	}
	else if (result != 0 && time < 7 && rest < 10)
	{
//		printf("[rest < 10 = [%lu]]\n", rest);
		ft_putchar(rest + 48); 
	}
}

int	ft_printf(char *str, ...)
{
	int	i;
	int	count;
	char	*arg_str;
	int	arg_int;
	unsigned int	arg_hexa;
	va_list	va;

	i = 0;
	va_start(va, str);
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			count++;
			ft_putchar(str[i++]);
		}
		else
		{
			if (str[i + 1] && str[i + 1] == 's')
			{
				arg_str = va_arg(va, char *);
				ft_putstr(arg_str);
				count = count + ft_strlen(arg_str);
			}
			if (str[i + 1] && str[i + 1] == 'd')
			{
				arg_int = va_arg(va, int);
				ft_putnbr(arg_int, &count);
			}
			if (str[i + 1] && str[i + 1] == 'x')
			{
				arg_hexa = va_arg(va, unsigned int);
				ft_putnbr_hexa(arg_hexa, &count);
			}
			i = i + 2;
		}
	}
	return (count);
}

int	main(int ac, char **av)
{
	int d = atoi(av[1]);
	int x = atoi(av[3]);
	int	ret1;
	int	ret2;
	ret1 = printf("OG = >>%d<< | >>%s<< | >>%x<<\n", d, av[2], x);
	ret2 = ft_printf("MY = >>%d<< | >>%s<< | >>%x<<\n", d, av[2], x);
	printf("OG ret = %d | MY ret = %d\n", ret1, ret2);
}
