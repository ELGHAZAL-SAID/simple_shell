#include "main.h"

/**
 * ready_cmd - commande were ready to excute.
 * @buffer: the current commande.
 * @cmd_type: the type of the commande.
 *
 * Return: 0.
 */
void ready_cmd(char **buffer, int cmd_type)
{
	pid_t pid;

	if (cmd_type == EXTERN_CMD || cmd_type == PATH_CMD)
	{
		pid = fork();
		if (pid == 0)
			exec_cmd(buffer, cmd_type);
		else
		{
			waitpid(pid, &st, 0);
			st >>= 8;
		}
	}
	else
		exec_cmd(buffer, cmd_type);
}
