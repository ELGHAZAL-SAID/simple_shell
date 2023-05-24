#include "main.h"


/**
 * ctrl_c - don't care about the ctrl+c.
 * @n: the int.
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * ctrl_D - exit the programme whene ctrl+d is entred.
 * @i: read char.
 * @command: command as string.
 * @env: enviroment.
 */
void ctrl_D(int i, char *command, link_t *env)
{
	if (i == 0)
	{
		free(command);
		free_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

}
