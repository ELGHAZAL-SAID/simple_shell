#include "main.h"

/**
 * rd_ln - reads the input.
 *
 * @i_eof: value of getline func
 * Return: string
 */
char *rd_ln(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
