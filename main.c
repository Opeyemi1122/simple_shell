#include "main.h"
#include <stdio.h>


/**
 * main - Reads in the input command and calls
 * other functions.
 *
 * Return: Always 0.
 */

int main(void);
int main(void)
{

	while (1)
	{
		char *input = NULL;
		size_t input_len;
		struct input_commands commands;
		ssize_t input_return;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		input_return = getline(&input, &input_len, stdin);

		if (input_return == -1)
		{
			perror("error.\n");
			free(input);
			exit(EXIT_FAILURE);
		}

		format_input(input, &commands);
		execute_command(&commands);

		free(input);

	}

	return (0);

}
