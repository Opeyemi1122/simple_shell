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

	write(1, "$ ", 2);
	num_char = getline(&buffer, &n, stdin);

	(void)num_char;

	free(buffer);

	return (0);

}
