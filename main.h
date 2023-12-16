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
#include <signal.h>
#include <fcntl.h>


#define BUFFERSIZE 1024
#define TOKENBUFFERSIZE 128
#define TOKENDELIMITER " \t\r\n\a"


/* Pointer of array of pointers to a strings called environment*/
extern char **environ;


/**
 * struct input_data - struct of all relevant data used on runtime
 * @argv: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @count: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */

typedef struct input_data
{
	char **argv;
	char *input;
	char **args;
	int status;
	int count;
	char **_environ;
	char *pid;
} runtime_data;



/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */

typedef struct builtin_s
{
	char *name;
	int (*f)(runtime_data *data);
} builtin_t;





/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;




/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */

typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;




/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */

typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;





char *_strcpy(char *dest, char *src);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
void shell_loop(runtime_data *data);
char *read_line(int *i_eof);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
int _atoi(char *s);
void get_sigint(int sig);
char *aux_itoa(int n);
char *_strcat(char *dest, const char *src);
int _isdigit(const char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_getenv(const char *name, char **_environ);
int _env(runtime_data *datash);
int get_len(int n);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
char *without_comment(char *in);
int check_syntax_error(runtime_data *datash, char *input);
char *rep_var(char *input, runtime_data *datash);
int split_commands(runtime_data *datash, char *input);
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void rev_string(char *s);
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(runtime_data *datash, char *input, int i, int bool);
int check_syntax_error(runtime_data *datash, char *input);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, runtime_data *datash);
int split_commands(runtime_data *datash, char *input);
char **split_line(char *input);
void check_env(r_var **h, char *in, runtime_data *data);
int check_vars(r_var **h, char *in, char *st, runtime_data *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
int exec_line(runtime_data *datash);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(runtime_data *datash);
int check_error_cmd(char *dir, runtime_data *datash);
int cmd_exec(runtime_data *datash);
char *_getenv(const char *name, char **_environ);
int cmp_env_name(const char *nenv, const char *name);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, runtime_data *datash);
int _setenv(runtime_data *datash);
int _unsetenv(runtime_data *datash);
void cd_dot(runtime_data *datash);
void cd_to(runtime_data *datash);
void cd_previous(runtime_data *datash);
void cd_to_home(runtime_data *datash);
int cd_shell(runtime_data *datash);
int (*get_builtin(char *cmd))(runtime_data *datash);
int exit_shell(runtime_data *datash);
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);
int get_help(runtime_data *datash);
int get_error(runtime_data *datash, int eval);









#endif
