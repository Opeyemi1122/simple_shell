#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	int status, j = 0;
	char **array;
	pid_t child_pid;
	
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&buf, &buf_size, stdin);
		token = strtok(buf, "\t\n");
		array = malloc(sizeof (char *) * 1024);

		while (token)
		{
			array[j] = token;
			token = strtok(NULL, "\t\n");
			j++;
		}
			array[j] = NULL;
			child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}
		j = 0;
		free(array);
	}
}
