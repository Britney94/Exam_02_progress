/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerework.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:23:57 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/24 16:29:25 by kejebane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
		if (s[i] == c)
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

	i = 0;
	while (av[1][i])
	{
		if (is_in(av[1][i], av[2]) == 1 && prior(i, av[1]) == 0)
			ft_putchar(av[1][i]);
		i++;
	}
}

