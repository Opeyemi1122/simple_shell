#include <stdio.h>
#include <unistd.h>

/**
* main - PPID
*
* Return: Always 0.
*/
int main(void)
{
	pid_t parentPid_pid;

	parentPid_pid = getppid();
	printf("%u\n", parentPid_pid);
	return (0);
}
