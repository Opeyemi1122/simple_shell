#include "main.h"
#include <stdio.h>


/**
 * main - Reads in the input command and calls
 * other functions.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *input = NULL;
	size_t input_len = 0;
	struct input_commands commands;
	int input_return = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		input_return = getline(&input, &input_len, stdin);

		if (input_return == -1)
		{
			exit(0);
		}
		if (input[_strlen(input) - 1] == '\n')
		{
			input[_strlen(input) - 1] = '\0';
		}

		format_input(input, &commands);
		execute_command(&commands);

	}

	free(input);

	return (0);

}
