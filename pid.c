#include <stdio.h>
#include <unistd.h>


/**
 * main - PID (Process ID)
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();

	write(1, my_pid, strlen(my_pid));
	return (0);
}
