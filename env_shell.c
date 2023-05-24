#include "main.h"

/**
 * env_shell_linked - create a list from env var.
 * @env: enviroment variables.
 * Return: the list.
 */
link_t *env_shell_linked(char **env)
{
	link_t *head;
	int x = 0;

	head = NULL;
	while (env[x] != NULL)
	{
		add_node_end(&head, env[x]);
		x++;
	}
	return (head);
}

/**
 * env_shell - write env var.
 * @cmd: command
 * @env: env variables
 * Return: always 0.
 */
int env_shell(char **cmd, link_t *env)
{
	free_arr(cmd);
	write_list(env);
	return (0);

}
