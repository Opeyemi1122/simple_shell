#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * main - Combined fork, wait and exec functions
 *
 * Return: Always 0.
 */


int main(void)
{
	pid_t child_pid;
	int status;
	int i;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 1; i <= 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	
	if (child_pid == 0)
	{
		execve("/usr/bin/ls", args, NULL);
		perror("Error:");
		exit(1);

	}
	else
	{
		/*parent*/
		wait(&status);
	}

	return (0);
}
