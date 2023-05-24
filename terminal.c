#include "shell.h"

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
 * built_in - handles builtins
 * @env: enviroment variable
 * @num: take in nth user command typed to write error message
 * @command: command to free
 * Return: 1 if acted on builtin, else 0
 */
int built_in(char **token, list_t *env, int num, char **command)
{
	int x = 0;

	if (_strcmp(token[0], "exit") == 0)
	{
		x = __exit(token, env, num, command);
	}
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		x = 1;
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		x = _cd(token, env, num);
	}
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		x = 1;
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		x = 1;
	}
	return (x);
}

/**
 * ctrl_D - exits program if Ctrl-D is input
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env: enviroment variable linked list
 */
void ctrl_D(int i, char *command, list_t *env)
{
	if (i == 0)
	{
		free(command);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * terminal - executes user's commands.
 * @envirment: envrionment variables
 * Return: 0 on success
 */
int terminal(char **envirment)
{
	list_t *e;
	size_t x = 0;
	size_t y = 0;
	int i = 0;
	int str = 0;
	char *cmd, *n_cmd, **tk;

	e = env_linked_list(envirment);
	do {
		i++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(e);
		signal(SIGINT, ctrl_c);
		cmd = NULL;
		x = 0;
		x = get_line(&cmd);
		ctrl_D(x, cmd, e);
		n_cmd = cmd;
		cmd = ignore_space(cmd);
		y = 0;
		while (cmd[y] != '\n')
			y++;
		cmd[y] = '\0';
		if (cmd[0] == '\0')
		{
			free(n_cmd);
			continue;
		}
		tk = NULL;
		tk = _str_tok(cmd, " ");
		if (n_cmd != NULL)
			free(n_cmd);
		str = built_in(tk, e, i, NULL);
		if (str)
			continue;
		str = _execve(tk, e, i);
	} while (1);
	return (str);
}
