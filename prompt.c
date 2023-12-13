#include "main.h"


/**
 * main - Aprompt for input
 *
 * Return: Always 0.
 */

int main(void)
{
	char *buffer;
	ssize_t num_char;
	size_t n = 10;

	buffer = malloc(sizeof(char) * n);

	printf("$ ");
	num_char = getline(&buffer, &n, stdin);

	printf("%lu\n", num_char);

	free(buff);

	return (0);

}
