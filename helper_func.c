#include "main.h"

/**
 * ignore_space - return string without spaces in front
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
 * @cmd: the commande..
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
 * rm_comment - remove comments from a command.
 * @cmd: the commande.
 *
 * Return: 0.
 */

void rm_comment(char *cmd)
{
	int i = 0;

	if (cmd[i] == '#')
		cmd[i] = '\0';
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '#' && cmd[i - 1] == ' ')
			break;
		i++;
	}
	cmd[i] = '\0';
}

/**
 *_strtok_r - tokenizing a string
 *@string: string to be tokenized
 *@delimiter: delimiter to used to tokenize the string
 *@saved_ptr: pointer to track of the next token
 *Return: The next token
 */
char *_strtok_(char *string, char *delimiter, char **saved_ptr)
{
	char *fin = NULL;

	if (string == NULL)
		string = *saved_ptr;

	if (*string == '\0')
	{
		*saved_ptr = string;
		return (NULL);
	}

	string += strspn(string, delimiter);
	if (*string == '\0')
	{
		*saved_ptr = string;
		return (NULL);
	}

	fin = string + strcspn(string, delimiter);
	if (*fin == '\0')
	{
		*saved_ptr = fin;
		return (string);
	}

	*fin = '\0';
	*saved_ptr = fin + 1;
	return (string);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer already allocated with a call to malloc
 * @oldSize: size of pointer
 * @newSize: new size of memory to be allocated
 *
 * Return: pointer to the new allocated memoty
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