#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

/*#define MAX_COMMAND_LENGTH (100)*/
#define MAX_ARGUMENTS (10)


/**
 * struct input_commands - Struct different commands.
 * @arguments: Input arguments.
 */

typedef struct input_commands
{
	char *arguments[MAX_ARGUMENTS];
} cmd;

extern char **environ;

void format_input(char *input, struct input_commands *commands);
void execute_command(struct input_commands *commands);
char *_strcpy(char *dest, char *src);
int _strlen(char *c);
int _strcmp(char *str1, char *str2);
void prompt(void);
int print_env(void);


#endif
