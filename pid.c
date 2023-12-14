#include "main.h"


/**
 * main - PID (Process ID)
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t my_pid;
	char pid_str[20];

	my_pid = getpid();

	snprintf(pid_str, sizeof(pid_str), "%d", my_pid);

	write(1, pid_str, strlen(pid_str));
	return (0);
}
