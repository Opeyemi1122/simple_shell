#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int j;
	int sum = 0;

	printf("argc = %d\n", ac);
	printf("argv content = argv\n");

	for (j = 1; j < ac; j++)
	{
		printf("argv[%d] = %s\n", j, av[j]);
		sum += atoi(av[1]);
	}
	printf("sum = %d\n", sum);
	return (0);
}
