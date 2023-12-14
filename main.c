#include "main.h"

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
		pid_t child_pid;
		int status;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		input_return = getline(&input, &input_len, stdin);

		if (input_return == -1)
		{
			perror("error.\n");
			free(input);
			exit(EXIT_FAILURE);
		}

		format_input(input, &commands);

		if (_strcmp(commands.arguments[0], "exit") == 0)
			break;
		else if (_strcmp(commands.arguments[0], "env") == 0)
		{
			print_env();
			continue;
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork failure.\n");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
			execute_command(&commands);
		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("waitpid failure.\n");
				free(input);
				exit(EXIT_FAILURE);
			}
		}

		free(input);

	}

	return (0);

}
