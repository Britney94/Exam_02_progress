/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:11:11 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/23 17:30:38 by kejebane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		y;
	int		size;
	char	*res;

	i = 0;
	y = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
		res[i++] = s2[y++];
	res[i] = '\0';
	return (res);
}

int		get_next_line(char **line)
{
	char 			buffer[2];
	static char		*rest;
	int				reader;
	int				fd;

	fd = 0;
	reader = 1;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && reader != 0)
	{
		if ((reader = read(fd, buffer, 1)) == (-1))
			return (-1);
		buffer[reader] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	*line = push_line(rest);
	rest = 
