#include "main.h"

/**
 * free_data - frees structure bihi
 *
 * @datash: structure
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av, datash->input = NULL;
	datash->args = NULL, datash->status = 0, datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = _aux_itoa_(getpid());
}

/**
 * main - Entry point function
 *
 * @ac: count
 * @av: vector
 *
 * Return: 0 if success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;
	signal(SIGINT, _get_sig_int_), set_data(&datash, av);
	sh_lp(&datash), free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
