#include "main.h"

/**
 * ready_cmd - commande were ready to excute.
 * @buffer: the current commande.
 * @cmd_type: the type of the commande.
 *
 * Return: 0.
 */
void ready_cmd(char **buffer, int cmd_type)
{
	pid_t pid;

	if (cmd_type == EXTERN_CMD || cmd_type == PATH_CMD)
	{
		pid = fork();
		if (pid == 0)
			exec_cmd(buffer, cmd_type);
		else
		{
			waitpid(pid, &st, 0);
			st >>= 8;
		}
	}
	else
		exec_cmd(buffer, cmd_type);
}

/**
 * c_exit - frees list before exit.
 * @string: command as string.
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
 * @str: ccommand as string
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
		holder = _which(s[0], environ);
	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], number, environ);
		free_double_ptr(str);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, str, NULL) == -1)
			{
				not_found(s[0], number, environ);
				c_exit(str, environ);
			}
		}
		else
		{
			wait(&st);
			free_double_ptr(str);
			if (p == 0)
				free(holder);
		}
	}
	return (0);
}