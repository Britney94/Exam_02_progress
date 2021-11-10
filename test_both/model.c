#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int     ft_strlen(char *str)
{
    int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char    *ft_strjoin(char *remains, char *buffer)
{
    char *array;
    unsigned int size;
    int i;
    int j;

    if (!remains && !buffer)
        return (NULL);
    size = ft_strlen(remains) + ft_strlen(buffer);
    if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    i = 0;
    j = 0;
    if (remains)
    {
        while (remains[i])
        {
            array[j] = remains[i];
            i++;
            j++;
        }
        i = 0;
    }
    while (buffer[i])
    {
        array[j] = buffer[i];
        i++;
        j++;
    }
    array[size] = '\0';
    free((void *)remains);
    return (array);
}

char    *push_line(char *remains)
{
    int i;
    char *array;

    i = 0;
    while (remains[i] && remains[i] != '\n')
        i++;
    if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (remains[i] && remains[i] != '\n')
    {
        array[i] = remains[i];
        i++;
    }
    array[i] = '\0';
    return (array);
}

char    *cut_next_line(char *remains)
{
    int i;
    int j;
    char *array;

    i = 0;
    j = 0;
    while (remains[i] && remains[i] != '\n')
        i++;
    if (!remains[i])
    {
        free(remains);
        return (NULL);
    }
    if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
        return (NULL);
    i++;
    while (remains[i])
    {
        array[j] = remains[i];
        i++;
        j++;
    }
    array[j] = '\0';
    free(remains);
    return (array);
}

char	     *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    char *line;
    static char *remains;
    int count;

    count = 1;
//    fd = 0;
//    if (!line)
 //       return (-1);
    while (buffer[0] != '\n' && count != 0)
    {
        if ((count = read(fd, buffer, BUFFER_SIZE)) == (-1))
            return (NULL);
        buffer[count] = '\0';
        remains = ft_strjoin(remains, buffer);
    }
    line = push_line(remains);
    remains = cut_next_line(remains);
    return(line);
}

int	main(int ac, char **av)
{
	int	fd;
	int	b;
	char	*gnl;

//	fd = 0;
	fd = open("keele.txt", O_RDONLY);
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

