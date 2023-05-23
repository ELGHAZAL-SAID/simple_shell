#include "main.h"


/**
* clean_shell - clean cmd
*
* Return: non
*/

void clean_shell(void)
{
	char **buffer;
	int i = 0, cmd_type = 0, line;
	size_t size = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		line = getline(&ln, &size, stdin);
		while (line != -1)
		{
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
		exit(st);
	}
}

