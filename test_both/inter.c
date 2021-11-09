#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_in(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	prior(int x, char *s)
{
	int	i;

	i = x - 1;
	while (s[i])
	{
		if (s[i] == s[x])
			return (1);
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	while (av[1][i])
	{
		if (is_in(av[1][i], av[2]) == 1 && prior(i, av[1]) == 0)
			ft_putchar(av[1][i]);
		i++;
	}
}

