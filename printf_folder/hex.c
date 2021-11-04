#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n;

	n = atoi(av[1]);
	printf("int = %d\t||\thex = %x\n", n, n);
}
