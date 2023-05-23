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
		free(com);
		exit(st);
	}
	else if (num_token == 2)
	{
		arg = atoi(token[1]);
		if (arg == -1)
		{
			print(shell, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(token[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
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
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
