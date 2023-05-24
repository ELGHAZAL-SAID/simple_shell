#include "main.h"

/**
 * builtin_func - handles builtin functions
 * @env: env variables
 * @number: take in nth user command typed to write error message
 * @cmd: command to free
 * Return: 1 if on builtin behavior, else 0
 */
int builtin_func(char **token, link_t *env, int number, char **cmd)
{
	int i = 0;

	if (strcmp(token[0], "exit") == 0)
	{
		i = _quit(token, env, number, cmd);
	}
	else if (strcmp(token[0], "env") == 0)
	{
		env_shell(token, env);
		i = 1;
	}
	else if (strcmp(token[0], "cd") == 0)
	{
		i = change_dir(token, env, number);
	}
	else if (strcmp(token[0], "setenv") == 0)
	{
		setenv(&env, token);
		i = 1;
	}
	else if (strcmp(token[0], "unsetenv") == 0)
	{
		unsetenv(&env, token);
		i = 1;
	}
	return (i);
}
