#include "main.h"

/**
 * parsing_cmd - know the commande type.
 * @cmd: the commande.
 *
 * Return: type of the commande.
 */

int parsing_cmd(char *cmd)
{
	int i = 0;
	char *cmd_inter[] = {"env", "exit", NULL};
	char *p = 0;

	while (cmd[i] != 0)
	{
		if (cmd[i] == '/')
			return (EXTERN_CMD);
		i++;
	}
	i = 0;
	while (cmd_inter[i] != 0)
	{
		if (strcmp(cmd, cmd_inter[i]) == 0)
			return (INTERN_CMD);
		i++;
	}
	p = is_found(cmd);
	if (p != 0)
	{
		free(p);
		return (PATH_CMD);
	}
	return (INV_CMD);
}
