#include "main.h"


/**
* get_func = get cmd based on function
* @cmd: string to be checked
*
* Return: pointer to the chosen function
*/

void (*func_geter(char *cmd)(char **)
{
	int i;

	get_func map[] = {
		{"env", env_shell}, {"exit", _quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(cmd, map[i].cmd) == 0)
			return (map[i].func);
	}
	return (0);
}
