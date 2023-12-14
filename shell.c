#include "main.h"
#include <stdio.h>

/**
 * format_input - Formats the input string.
 * @input: The input string used to call the function.
 * @cmd: The input commands.
 */

void format_input(char *input, struct input_commands *cmd)
{
	char *token;
	int i;

	token = strtok(input, " \t\n");

	/*strcpy(cmd->name, token);*/

	i = 0;

	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		cmd->arguments[i] = token;
		token = strtok(NULL, " \t\n");

		i++;
	}

	cmd->arguments[i] = NULL;

}



/**
 * execute_command - Executes input command.
 * @cmd: Input command.
 */

void execute_command(struct input_commands *cmd)
{
	int status;
	pid_t child_pid;

	if (_strcmp(cmd->arguments[0], "env") == 0)
	{
		print_env();
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: ");
		exit(0);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd->arguments[0], cmd->arguments, NULL) == -1)
		{
			perror("Error:");
			return;
		}
	}
	else
	{
		wait(&status);

	}



}
