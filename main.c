#include "main.h"


char **cmd = NULL;
char *ln = NULL;
char *shell = NULL;
int st = 0;

/**
 * main - shell programe.
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * return: 0.
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char **buffer = NULL;
	size_t size = 0;
	int i = 0, cmd_type = 0, line;

	signal(SIGINT, ctrl_c_handler);
	shell = argv[0];

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
		i = 0;
		while (cmd[i] != 0)
		{
			buffer = _strtok(cmd[i], " ");
			if (buffer[0] == NULL)
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
