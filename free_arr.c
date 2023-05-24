#include "main.h"

/**
 * free_arr - free arrays in memory.
 * @string: array of strings
 */
void free_arr(char **string)
{
	int i = 0;

	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	free(string);
}