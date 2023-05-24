#include "main.h"

/**
 * token_len - token's string length
 * @str: a token
 * @index: index position in user's command typed into shell
 * @delimiter: delimeter
 * Return: token length
 */
int token_len(char *str, int index, char delimiter)
{
	int size = 0;

	while ((str[index] != delimiter) && (str[index] != '\0'))
	{
		index++;
		size++;
	}
	return (size);
}

/**
 * token_size - number of delimiters and ignore continuous del
 * @str: command typed into shell
 * @delimiter: delimeter
 * Return: number of delimiters
 */
int token_size(char *str, char delimiter)
{
	int x = 0, dlm = 0;

	while (str[x] != '\0')
	{
		if ((str[x] == delimiter) && (str[x + 1] != delimiter))
		{
			dlm++;
		}
		if ((str[x] == delimiter) && (str[x + 1] == '\0'))
		{
			dlm--;
		}
		x++;
	}
	return (dlm);
}

/**
 * rm_delm - version of string without parc delimiters
 * @str: string
 * @delimiter: delimiter
 * Return: new string
 */

char *rm_delm(char *str, char delimiter)
{
	while (*str == delimiter)
		str++;
	return (str);
}


/**
 * _strtok - make a string tokenized.
 * @str: the string.
 * @delimiter: delimiter to split the string.
 *
 * Return: all the tokens.
 */

char **_strtok(char *str, char *delimiter)
{
	int i = 0, ptr = 0, qtr = 0, j = 0, sz = 0, se = 0, t = 0;
	char **token = NULL, d_ch;

	d_ch = delimiter[0];
	str = rm_delm(str, d_ch);
	i = token_size(str, d_ch);
	token = malloc(sizeof(char *) * (i + 2));
	if (token == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (qtr < se)
	{
		if (str[qtr] != d_ch)
		{
			sz = token_len(str, qtr, d_ch);
			token[ptr] = malloc(sizeof(char) * (sz + 1));
			if (token[ptr] == NULL)
				return (NULL);
			j = 0;
			while ((str[qtr] != d_ch) && (str[qtr] != '\0'))
			{
				token[ptr][j] = str[qtr];
				j++;
				qtr++;
			}
			token[ptr][j] = '\0';
			t++;
		}
		if (qtr < se && (str[qtr + 1] != d_ch && str[qtr + 1] != '\0'))
			ptr++;
		qtr++;
	}
	ptr++;
	token[ptr] = NULL;
	return (token);
}
