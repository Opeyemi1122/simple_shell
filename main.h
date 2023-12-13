#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

/*#define MAX_COMMAND_LENGTH (100)*/
#define MAX_ARGUMENTS (10)

struct input_commands;

void format_input(char *input, struct input_commands *commands);
void execute_command(struct input_commands *commands);




/**
 * struct input_commands - Struct different commands.
 * @name: Command name
 * @arguments: Input arguments.
 */

typedef struct input_commands
{
	/*char name[MAX_COMMAND_LENGTH];*/
	char *arguments[MAX_ARGUMENTS];
} cmd;



#endif
