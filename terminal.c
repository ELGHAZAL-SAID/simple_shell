#include "main.h"


/**
 * terminal - executes user's commands.
 * @envirment: envrionment variables
 * Return: 0 on success
 */
int terminal(char **envirment)
{
	link_t *e;
	size_t x = 0;
	size_t y = 0;
	int i = 0;
	int str = 0;
	char *cmd, *n_cmd, **tk;

	e = env_shell_linked(envirment);
	do {
		i++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			clean_cmd(e);
		signal(SIGINT, ctrl_c);
		cmd = NULL;
		x = 0;
		x = read_line(&cmd);
		ctrl_D(x, cmd, e);
		n_cmd = cmd;
		cmd = rm_space(cmd);
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
		tk = _strtok(cmd, " ");
		if (n_cmd != NULL)
			free(n_cmd);
		str = builtin_func(tk, e, i, NULL);
		if (str)
			continue;
		str = _execve(tk, e, i);
	} while (1);
	return (str);
}
