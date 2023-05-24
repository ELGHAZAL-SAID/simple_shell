#include "main.h"


/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * ctrl_D - exits program if Ctrl-D is input
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env: enviroment variable linked list
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