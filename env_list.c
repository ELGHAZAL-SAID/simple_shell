#include "main.h"

/**
 * env_list - list of env variables.
 * @environ: enviroment variables
 * Return: list.
 */
link_t *env_list(char **environ)
{
	link_t *head;
	int i = 0;

	head = NULL;
	while (environ[i] != NULL)
	{
		add_node_end(&head, environ[i]);
		i++;
	}
	return (head);
}

/**
 * print_env - write env variables.
 * @string: the string commande.
 * @environ: enviroment variables.
 * Return: 0.
 */
int print_env(char **string, link_t *environ)
{
	free_arr(string);
	write_list(environ);
	return (0);
}