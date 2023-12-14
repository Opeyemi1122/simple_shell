#include "main.h"

/**
 * prompt - a function that prompts the user
 */

void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
