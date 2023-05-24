#include "main.h"


/**
 * terminal - executes user's commands.
 * @env: envrionment variables
 * Return: 0 on success
 */
int terminal(char **en)
{
	link_t *env;
	size_t p = 0, q = 0;
	int cdn = 0, xt = 0;
	char *command, *n_command, **token;

	env = env_shell_linked(en);
	do {
		cdn++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			clean_cmd(env);
		signal(SIGINT, ctrl_c);
		command = NULL;
		p = 0;
		p = read_line(&command);
		ctrl_D(p, command, env);
		n_command = command;
		command = rm_space(command);
		q = 0;
		while (command[q] != '\n')
			q++;
		command[q] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _strtok(command, " ");
		if (n_command != NULL)
			free(n_command);
		xt = builtin_func(token, env, cdn, NULL);
		if (xt)
			continue;
		xt = exe_ve(token, env, cdn);
	} while (1);
	return (xt);
}
