#include "main.h"

/**
 * main - prints the environment
 * @ac: Argument count
 * @av: Argument array
 * @env: Environment variable
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	unsigned int i;

	i = 0;

	(void)ac;
	(void)av;


	while (env[i] != NULL)
	{
		write(1, env[i], strlen(env[i]));
		i++;
	}
	return (0);
}
