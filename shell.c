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
		write(1, "#cisfun$ ", 10);

		input_return = getline(&input, &input_len, stdin);

		if (input_return == -1)
		{
			exit(0);
		}
		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
			break;


		format_input(input, &commands);
		execute_command(&commands);

	}

	free(input);

	return (0);

}

/**
 * format_input - Formats the input string.
 * @input: The input string used to call the function.
 * @commands: The input commands.
 */

void format_input(char *input, struct input_commands *cmd)
{
	char *token;
	int i;

	token = strtok(input, " \t\n");

	/*strcpy(cmd->name, token);*/

	i = 0;

	while (token != NULL)
	{
		cmd->arguments[i] = malloc(sizeof(char) * (strlen(token) + 1));
		/*token = strtok(NULL, "\t\n");*/
		cmd->arguments[i] = token;
		token = strtok(NULL, " \t\n");

		i++;
	}

	cmd->arguments[i] = NULL;

}



/**
 * execute_command - Executes input command.
 * @commands: Input command.
 */

void execute_command(struct input_commands *cmd)
{

	int status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: ");
		exit(0);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd->arguments[0], cmd->arguments, NULL) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
	}



}
