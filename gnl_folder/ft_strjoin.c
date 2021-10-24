/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:11:11 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/24 19:06:49 by kejebane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

char	*ft_strdup(char *s)
{
	int		i;
	char	*res;

	i = ft_strlen(s);
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char 			buffer[2];
	static char		*rest;
	static int		time;
	int				reader;
//	int				fd;

//	fd = 0;
	reader = 1;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && reader != 0)
	{
		reader = read(fd, buffer, 1);
		if (reader == -1)
			return (-1);
		buffer[reader] = '\0';
		if (time)
			free(rest);
		rest = ft_strjoin(rest, buffer);
	}
//	printf("line = %s", *line);
	*line = ft_strdup(rest);
	time++;

	return (reader);
}

int        main(int argc, char **argv)
{
    char        *line;
    int            fd1;
	int			ret;

    (void)argc;
//    fd1 = 0;
	fd1 = open(argv[1], O_RDONLY);
    while ((ret = get_next_line(fd1, &line)) == 1)
	{
		printf("[%d] - >>%s<<\n", ret, line);
	}
    printf("[%d] - >>%s<<\n", ret, line);
	close(fd1);
    return (0);
}
