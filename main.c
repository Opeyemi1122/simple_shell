#include "main.h"

/**
 * free_input_data - frees data structure
 *
 * @data: data structure
 * Return: no return
 */
void free_input_data(runtime_data *data)
{
	unsigned int i;

	for (i = 0; data->_environ[i]; i++)
	{
		free(data->_environ[i]);
	}

	free(data->_environ);
	free(data->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @data: data structure
 * @argv: argument vector
 * Return: no return
 */
void set_data(runtime_data *data, char **argv)
{
	unsigned int i;

	data->argv = argv;
	data->input = NULL;
	data->args = NULL;
	data->status = 0;
	data->count = 1;

	for (i = 0; environ[i]; i++)
		;

	data->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->_environ[i] = _strdup(environ[i]);
	}

	data->_environ[i] = NULL;
	data->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **argv)
{
	runtime_data data;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&data, argv);
	shell_loop(&data);
	free_input_data(&data);
	if (data.status < 0)
		return (255);
	return (data.status);
}
