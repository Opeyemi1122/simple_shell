#include <stdio.h>
#include <stdlib.h>

/**
 * main - Printing the name of a function and its arguments
 *
 * @ac: number of input arguements.
 * @av: input arguments.
 *
 * Return: Always 0.
 *
 */

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
