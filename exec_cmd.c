#include "main.h"

/**
 * exec_cmd - execut a command
 *@token: token to execut
 *@cmd_type: type of the command
 *
 *Return: non.
 */


void exec_cmd(char **token, int cmd_type)
{
	void (*func)(char **cmd);

	if (cmd_type == EXTERN_CMD)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror(getenv("PWD"));
			exit(2);
		}
	}
	if (cmd_type == PATH_CMD)
	{
		if (execve(path_checker(token[0]), token, NULL) == -1)
		{
			perror(getenv("PWD"));
			exit(2);
		}
	}
	if (cmd_type == INTERNAL_CMD)
	{
		func = func_geter(token[0]);
		func(token);
	}
	if (cmd_type == INV_CMD)
	{
		printf("%s\n", shell);
		printf(":1:");
		printf("%s\n", token[0]);
		printf(": not found\n");
		st = 127;
	}
}

