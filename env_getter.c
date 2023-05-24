#include "main.h"

/**
 * strdup_c - string duplication without first bytes
 * @string: string to duplicate
 * @num: number of bytes to exclude
 * Return: string
 */
char *strdup_c(char *string, int num)
{
	char *dup_str;
	int i, size = 0;

	if (string == NULL)
		return (NULL);

	while (*(string + size))
		size++;
	size++;

	dup_str = malloc(sizeof(char) * (size - num));
	if (dup_str == NULL)
		return (NULL);

	i = 0;
	while (i < (size - num))
	{
		*(dup_str + i) = *(string + num + i);
		i++;
	}
	return (dup_str);
}

/**
 * env_getter - finds and returns a copy of the requested enviroment variable
 * @string: string to store it in
 * @env: entire set of enviroment variables
 * Return: copy of requested enviroment variable
 */
char *env_getter(char *string, link_t *env)
{
	int i = 0, num = 0;

	while (env != NULL)
	{
		i = 0;
		while ((env->value)[i] == string[i])
			i++;
		if (string[i] == '\0' && (env->value)[i] == '=')
			break;
		env = env->next;
	}

	while (string[num] != '\0')
		num++;
	num++;
	return (strdup_c(env->value, num));
}