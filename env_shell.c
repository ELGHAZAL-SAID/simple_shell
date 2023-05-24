#include "main.h"

/**
 * env_linked - creates a linked list from enviroment variables
 * @env: enviroment variables
 * Return: linked list
 */
link_t *env_shell_linked(char **env)
{
	link_t *head;
	int x = 0;

	head = NULL;
	while (env[x] != NULL)
	{
		add_end_node(&head, env[x]);
		x++;
	}
	return (head);
}

/**
 * _env - prints env variables
 * @cmd: command
 * @env: env variables
 * Return: 0 on success
 */
int env_shell(char **cmd, link_t *env)
{
	free_double_ptr(cmd);
	print_list(env);
	return (0);
}