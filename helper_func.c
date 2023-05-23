#include "main.h"

/**
 * display - display prompt message.
 *
 * Return: 0.
 */
void display(void)
{
	printf("#cisfun$ ");
}


/**
 * rm_newline - remove a new line from a commande.
 * @cmd: the commande..
 *
 * Return: 0.
 */

void rm_newline(char *cmd)
{
	int i = 0;

	while (cmd[i] != 0)
	{
		if (cmd[i] == '\n')
			break;
		i++;
	}
	cmd[i] = 0;
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
		cmd[i] = 0;
	while (cmd[i] != 0)
	{
		if (cmd[i] == '#' && cmd[i - 1] == ' ')
			break;
		i++;
	}
	cmd[i] = 0;
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
	char *fin;

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
 * @old_s: size of pointer
 * @new_s: new size of memory to be allocated
 *
 * Return: pointer to the new allocated memoty
 */
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
	void *tm_block;
	unsigned int i;

	if (ptr == NULL)
	{
		tm_block = malloc(new_s);
		return (tm_block);
	}
	else if (new_s == old_s)
		return (ptr);
	else if (new_s == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		tm_block = malloc(new_s);
		if (tm_block != NULL)
		{
			for (i = 0; i < _min(old_s, new_s); i++)
				*((char *)tm_block + i) = *((char *)ptr + i);
			free(ptr);
			return (tm_block);
		}
		else
			return (NULL);

	}
}
