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
	pid_t childPid;
	int status;
	int p;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (p = 1; p <= 5; p++)
	{
		childPid = fork();
		if (childPid == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	
	if (childPid == 0)
	{
		execve("/usr/bin/ls", args, NULL);
		perror("Error:");
		exit(1);

	}
	else
	{
		wait(&status); /*parent*/
	}

	return (0);
}
