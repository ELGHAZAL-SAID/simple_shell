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


/**
 * unsetenv_ - remove node in environment linked list
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success
 */
int unsetenv_(link_t **env, char **str)
{
	int idx = 0, y = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Less arguments provided\n", 18);
		free_arr(str);
		return (-1);
	}
	idx = is_found_env(*env, str[1]);
	free_arr(str);
	if (idx == -1)
	{
		write(STDOUT_FILENO, "Not found\n", 11);
		return (-1);
	}
	y = rm_node_int_at_index(env, idx);
	if (y == -1)
	{
		write(STDOUT_FILENO, "Not found\n", 11);
		return (-1);
	}
	return (0);
}

/**
 * setenv_ - create or modify existing environment variable in linked list
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success else 1
 */
int setenv_(link_t **env, char **str)
{
	int idx = 0, x = 0;
	char *cat;
	link_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_arr(str);
		return (-1);
	}
	cat = strdup(str[1]);
	cat = strcat(cat, "=");
	cat = strcat(cat, str[2]);
	idx = is_found_env(*env, str[1]);
	if (idx == -1)
	{
		add_node_end(env, cat);
	}
	else
	{
		holder = *env;
		while (x < idx)
		{
			holder = holder->next;
			x++;
		}
		free(holder->value);
		holder->value = strdup(cat);
	}
	free(cat);
	free_arr(str);
	return (0);
}
