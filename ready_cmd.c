#include "main.h"


/**
 * exit_c - free the list.
 * @string: string.
 * @environ: env.
 */
void exit_c(char **string, link_t *environ)
{
	free_arr(string);
	free_list(environ);
	_exit(0);
}

/**
 * exe_ve - execute command.
 * @str: command as string
 * @environ: environment variable
 * @number: num error
 * Return: 0 always.
 */
int exe_ve(char **str, link_t *environ, int number)
{
	char *holder;
	int st = 0, p = 0;
	pid_t pid;


	if (access(str[0], F_OK) == 0)
	{
		holder = str[0];
		p = 1;
	}
	else
		holder = _which_cmd(str[0], environ);
	if (access(holder, X_OK) != 0)
	{
		is_not_found(str[0], number, environ);
		free_arr(str);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, str, NULL) == -1)
			{
				is_not_found(str[0], number, environ);
				exit_c(str, environ);
			}
		}
		else
		{
			wait(&st);
			free_arr(str);
			if (p == 0)
				free(holder);
		}
	}
	return (0);

}
