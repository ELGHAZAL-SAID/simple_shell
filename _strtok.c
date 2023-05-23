#include "main.h"

/**
 * _strtok - make a string tokinized.
 * @str: the string.
 * @delimiter: delimiter to split the string.
 *
 * Return: all the tokens.
 */

char **_strtok(char *str, char *delimiter)
{
	int n_delimiter = 0;
	char **p = NULL, *token = NULL, *d = NULL;

	token = _strtok_(str, delimiter, &d);
	while (token != NULL)
	{
		p = _realloc(p, sizeof(*p) * n_delimiter, sizeof(*p) * (n_delimiter + 1));
		p[n_delimiter] = token;
		token = _strtok_(NULL, delimiter, &d);
		n_delimiter++;
	}
	p = _realloc(p, sizeof(*p) * n_delimiter, sizeof(*p) * (n_delimiter + 1));
	p[n_delimiter] = NULL;

	return (p);
}
