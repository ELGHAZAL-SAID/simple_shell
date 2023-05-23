#include "main.h"


char **cmd = 0;
char *ln = 0;
char *shell = 0;
int st = 0;

/**
 * main - shell programe.
 *
 * return: 0.
 */

int main(void)
{
	char **buffer = 0;
	size_t size = 0;
	int i = 0, cmd_type = 0, line;

	while (1)
	{
		clean_shell();
		display();
		line = getline(&ln, &size, stdin);
		if (line == -1)
		{
			free(ln);
			exit(st);
		}
		rm_newline(ln);
		rm_comment(ln);
		cmd = _strtok(ln, ";");
		while (cmd[i] != 0)
		{
			buffer = _strtok(cmd[i], " ");
			if (buffer[0] == 0)
			{
				free(buffer);
				break;
			}
			cmd_type = parsing_cmd(buffer[0]);
			ready_cmd(buffer, cmd_type);
			free(buffer);
			i++;
		}
		free(cmd);
	}
	free(ln);
	return (st);
}
