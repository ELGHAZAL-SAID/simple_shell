#include "main.h"

/**
 * _quit - exits the shell
 * @token: command
 * Return: non
 */

/**
 * __exit - frees user input and then exits with a value
 * @str: user's command into shell
 * @env:  environment variable to free at error
 * @number:  nth user command line input to print in error message
 * @cmd:  command to free
 * Return: 0 if success else 2
 */
int _quit(char **str, link_t *env, int number, char **cmd)
{
	int ls = 0;

	if (str[1] != NULL)
		ls = atoi(str[1]);

	if (ls == -1)
	{
		illegal_args_number(str[1], number, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (cmd != NULL)
		free_double_ptr(cmd);
	exit(ls);

}
