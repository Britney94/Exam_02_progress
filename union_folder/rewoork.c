/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewoork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:18:30 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/23 14:40:55 by kejebane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_in(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int		prior(int x, char *s)
{
	int		i;

	i = x - 1;
	while (i >= 0)
	{
		if (s[i] == s[x])
			return (1);
		i--;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (av[1][i])
	{
		if (prior(i, av[1]) == 0)
			ft_putchar(av[1][i]);
		i++;
	}
	while (av[2][y])
	{
		if (is_in(av[2][y], av[1]) == 0 && prior(y, av[2]) == 0)
			ft_putchar(av[2][y]);
		y++;
	}
}

