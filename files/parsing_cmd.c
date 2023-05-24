#include "main.h"

/**
 * builtin_func - handle functions
 * @token: the token.
 * @env: env variables
 * @number: number.
 * @cmd: cmd to free it.
 * Return: 1 or 0.
 */
int builtin_func(char **token, link_t *env, int number, char **cmd)
{
	int i = 0;

	if (_strcmp(token[0], "exit") == 0)
	{
		i = _quit(token, env, number, cmd);
	}
	else if (_strcmp(token[0], "env") == 0)
	{
		env_shell(token, env);
		i = 1;
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = change_dir(token, env, number);
	}
	else if (_strcmp(token[0], "setenv") == 0)
	{
		setenv_(&env, token);
		i = 1;
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		unsetenv_(&env, token);
		i = 1;
	}
	return (i);
}
