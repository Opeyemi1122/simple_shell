#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int j;

	printf("argv content = argv[]\n");

	while (*av != NULL)
	{
		printf("argv = %s\n", *av);
		av++;
	}
	return (0);
}
