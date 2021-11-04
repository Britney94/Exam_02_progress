#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_bzero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		s[i++] = '\0';
}

int	hex_len(unsigned long int nb)
{
	int	res;
	unsigned long int result;

	res = 0;
	if (!nb)
		return (0);
	result = nb;
	while (result != 0)
	{
		result = result / 16;
		res++;
	}
	return (res);
}

char	*itohexa(unsigned long int  n)
{
//	int 	rest;
//	int	result;
	unsigned long int 	rest;
	unsigned long int	result;
	char	*hex;
	int 	k;
	int 	hex_digit_nb;

	result = n;
	hex_digit_nb = hex_len(n);
	printf("hex_digit_nb = %d\n", hex_digit_nb);
	hex = malloc(sizeof(char) * (hex_digit_nb + 1));
	ft_bzero(hex);
	k = 0;
	while (result != 0)
	{
		rest = result % 16;
		result = result / 16;
		if (rest >= 10)
			hex[k] = rest - 10 + 97;
		else
			hex[k] = rest + 48;
		k++;
	}
	while (k < 9)
		hex[k++] = '\0';
	return (hex);
}

void	ft_putrev(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	printf("i = %d\n", i);
	ft_putchar('#');
	while (s[i] && i >= 0)
		ft_putchar(s[i--]);
	ft_putchar('#');
}

void	full(int nb)
{
	char	*s1;
	char	*s2;

	s1 = itohexa(nb);
	ft_putrev(s1);
	free(s1);
}

int	main(int ac, char **av)
{
	unsigned int 	n;
//	va_list va;

	n = atoi(av[1]);
	full((unsigned int)n);
	printf("\tOG >>>%x<<<\n", n);
}
