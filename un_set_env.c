#include "main.h"

/**
 * find_env - find given environment variable in linked list
 * @env: environment variable linked list
 * @str: variable name
 * Return: idx of node in linked list
 */

int is_found_env(link_t *env, char *str)
{
	int j = 0, idx = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->value)[j] == str[j])
			j++;
		if (str[j] == '\0')
			break;
		env = env->next;
		idx++;
	}
	if (env == NULL)
		return (-1);
	return (idx);
}