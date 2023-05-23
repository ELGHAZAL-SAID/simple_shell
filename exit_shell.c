#include "main.h"

/**
 * _quit - exits the shell
 * @token: command
 * Return: non
 */

void _quit(char **token)
{
	int num_token;
	int arg;

	for (num_token = 0; *(token + num_token) != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(token);
		free(ln);
		free(cmd);
		exit(st);
	}
	else if (num_token == 2)
	{
		arg = atoi(token[1]);
		if (arg == -1)
		{
			printf("%s : 1: exit: Illegal number: %s\n",shell ,token[1]);;
			st = 2;
		}
		else
		{
			free(ln);
			free(token);
			free(cmd);
			exit(arg);
		}
	}
	else
		printf("$: exit doesn't take more than one argument\n");

}
