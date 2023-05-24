#include "main.h"

/**
 * _quit - exits the shell
 * @str: command.
 * @env: envirement.
 * @number: number.
 * @cmd: the command.
 * Return: nothing.
 */
int _quit(char **str, link_t *env, int number, char **cmd)
{
	int ls = 0;

	if (str[1] != NULL)
		ls = atoi(str[1]);

	if (ls == -1)
	{
		illegal_args_number(str[1], number, env);
		free_arr(str);
		return (2);
	}
	free_arr(str);
	free_list(env);
	if (cmd != NULL)
		free_arr(cmd);
	exit(ls);

}
