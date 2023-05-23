#include "main.h"

/**
 * display - display prompt message.
 *
 * Return: 0.
 */
void display(void)
{
	printf("#cisfun$ ");
}

/**
 * print_err - print error.
 *
 * Return: 0.
 */
void print_err(void)
{
	printf("./shell: No such file or directory");
}

/**
 * rm_newline - remove a new line from a commande.
 * @cmd: the commande..
 *
 * Return: 0.
 */

void rm_newline(char *cmd)
{
	int i = 0;

	while (cmd[i] != 0)
	{
		if (cmd[i] == '\n')
			break;
		i++;
	}
	cmd[i] = 0;
}

/**
 * rm_comment - remove comments from a command.
 * @cmd: the commande.
 *
 * Return: 0.
 */

void rm_comment(char *cmd)
{
	int i = 0;

	if (cmd[i] == '#')
		cmd[i] = 0;
	while (cmd[i] != 0)
	{
		if (cmd[i] == '#' && cmd[i - 1] == ' ')
			break;
		i++;
	}
	cmd[i] = 0;
}
