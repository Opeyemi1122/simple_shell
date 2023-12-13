#include "main.h"

/**
 * main - Prints enironment variable
 *
 * Return: Always 0.
 */

int main(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], strlen(environ[i]));
		i++;
	}

	return (0);
}
