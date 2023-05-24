#include "main.h"

/**
 * rm_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *rm_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}


/**
 * rm_newline - remove a new line from a commande.
 * @cmds: the commande..
 *
 * Return: 0.
 */

void rm_newline(char *cmds)
{
	int i = 0;

	while (cmds[i] != '\0')
	{
		if (cmds[i] == '\n')
			break;
		i++;
	}
	cmds[i] = '\0';
}


/**
 * _realloc - ellocate some memory.
 * @ptr: memory already allocated.
 * @oldSize: the old size.
 * @newSize: the new size.
 *
 * Return: the new memory allocated.
 */

void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize)
{
	void *pointer;
	unsigned int i;

	if (newSize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (newSize == oldSize)
		return (ptr);

	if (ptr == NULL)
	{
		pointer = malloc(newSize);
		if (pointer == NULL)
			return (NULL);
		else
			return (pointer);
	}

	pointer = malloc(newSize);
	if (pointer == NULL)
		return (NULL);

	for (i = 0; i < oldSize && i < newSize; i++)
		*((char *)pointer + i) = *((char *)ptr + i);
	free(ptr);

	return (pointer);

}
