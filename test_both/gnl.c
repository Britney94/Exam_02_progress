#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int	i;
	char	*res;

	if (!s)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	y;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2); 
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	y = 0;
	while (s2[y])
		res[i++] = s2[y++];
	res[i] = '\0';
	return (res);
}

char	*retrieve_after_newline(char *s)
{
	int	i;
	int	y;
	int	cut;
	char 	*res;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	y = 0;
	cut = i;
	while (s[i])
	{
		i++;
		y++;
	}
	res = malloc(sizeof(char) * (y + 1));
	y = 0;
	if (!res)
		return (NULL);
	while (s[cut])
		res[y++] = s[cut++];
	res[y] = '\0';
	return (res);
}

char	*cut_before_newline(char *s)
{
	int	i;
	int	nl;
	char	*res;

	i = 0;
	nl = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != 10)
		i++;
	if (s[i] == 10)
		nl = 1;;
	res = malloc(sizeof(char) * (i + nl + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != 10)
	{
		res[i] = s[i];
		i++;
	}
	if (nl == 1)
		res[i] = '\n';
	res[i] = '\0';
	return (res);
}

int	is_in(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	nb_newline(char *s)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	int	reader;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	char	*line;
	static char	*all;
	static int	time;

	reader = 1;
/*	if (time)
	{
		printf("time - buff = [%s]\n", buff);
//		all = ft_strdup(after);
		if (nb_newline(buff) == 1)
			all = retrieve_after_newline(buff + 1);
		else if (nb_newline(buff) >= 2)
		{
			tmp = ft_strdup(after);
			free(after);
			after = retrieve_after_newline(tmp);
			free(tmp);
			tmp = ft_strdup(all);
			free(all);
			all = cut_before_newline(tmp);
			free(tmp);
			return (all);
		}
	}
*/
//	while (reader > 0 && is_in('\n', buff) == 0)
	while (reader > 0 && buff[0] != '\n')
//	while (reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		printf("reader = %d || ", reader);
		if (reader < 0)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		printf("buff = [%s]\n", buff);
		if (time == 0)
			all = ft_strdup(buff);
		else
		{
			tmp = ft_strdup(all);
			free(all);
			all = ft_strjoin(tmp, buff);
			free(tmp);
		}
		time++;
//		if (is_in('\n', buff) == 1)
//			break;
	}
	line = cut_before_newline(all);
	tmp = ft_strdup(all);
	free(all);
	all = retrieve_after_newline(tmp);
	free(tmp);
	return (line);
}

int	main(int ac, char **av)
{
	int	fd;
	int	b;
	char	*gnl;

	fd = 0;
//	fd = open("keele.txt", O_RDONLY);
	gnl = get_next_line(fd);
	printf(">>>%s<<<\n", gnl);
	free(gnl);
	gnl = get_next_line(fd);
	printf(">>>%s<<<\n", gnl);
	free(gnl);
	gnl = get_next_line(fd);
	printf(">>>%s<<<\n", gnl);
	free(gnl);
/*	b = 1;
	while (b == 1)
	{	
		gnl = get_next_line(fd);
		if (gnl == NULL)
			b++;
		printf(">>>%s<<<\n", gnl);
	}
*/
}
