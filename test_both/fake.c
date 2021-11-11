#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	unsigned int size;
	int	y;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	y = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	while (s2[y])
		res[i++] = s2[y++];
	res[i] = '\0';
	free((void *)s1);
	return (res);
}

char	*cut_before_nl(char *s)
{
	int	i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*retrieve_after_nl(char *s)
{
	int	i;
	int	y;
	char	*res;

	i = 0;
	y = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (s[i])
	{
		res[y] = s[i];
		y++;
		i++;
	}
	res[y] = '\0';
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	int		reader;
	static char	*all;
	char		buff[BUFFER_SIZE + 1];
	char		*line;

	reader = 1;
	while (reader != 0 && buff[0] != '\n')
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == (-1))
			return (NULL);
		buff[reader] = '\0';
		all = ft_strjoin(all, buff);
	}
	line = cut_before_nl(all);
	all = retrieve_after_nl(all);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("keele.txt", O_RDONLY);
	line = get_next_line(fd);
	printf(">>>%s<<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>>%s<<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>>%s<<<\n", line);
	free(line);
}



