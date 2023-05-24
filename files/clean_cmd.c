#include "main.h"

/**
 * _ignore - ignores spaces & newlines
 * @str: env variables
 * Return: new string
 */
char *_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * clean_cmd - handles pipes commands into shell
 * @env: env variables
 */
void clean_cmd(link_t *env)
{
	size_t p = 0, q = 0;
	int cdn = 0, xt = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	p = rd_ln(&command);
	if (p == 0)
	{
		free(command);
		exit(0);
	}

	n_command = command;
	command = _ignore(command);
	n_line = _strtok(command, "\n");

	if (n_command != NULL)
		free(n_command);
	q = 0;
	while (n_line[q] != NULL)
	{
		cdn++;
		token = NULL;
		token = _strtok(n_line[q], " ");
		xt = builtin_func(token, env, cdn, n_line);
		if (xt)
		{
			q++;
			continue;
		}
		xt = exe_ve(token, env, cdn);
		q++;
	}
	free_arr(n_line);
	free_list(env);
	exit(xt);
}
