#include "main.h"


/**
 * c_t_size - returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter ;
 * Return: number of tokens
 */
int count_delimiters(char *str, char delimiter)
{
	int x = 0, dlm = 0;

	while (str[x] != '\0')
	{
		if (str[x] == delimiter)
		{
			dlm++;
		}
		x++;
	}
	return (dlm);
}


/**
 * c_str_tok - tokenizes a string even the continuous delim with empty string
 * @str: user's command typed into shell
 * @delimiter: delimeter
 * Return: an array of tokens
 */
char **tokenize_string(char *str, char *delimiter)
{
	int bs = 0, p = 0, q = 0, r = 0, s = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delimiter[0];
	bs = count_delimiters(str, d_ch);
	toks = malloc(sizeof(char *) * (bs + 2));
	if (toks == NULL)
		return (NULL);

	while (str[t] != '\0')
		t++;
	while (q < t)
	{
		s = token_len(str, q, d_ch);
		toks[p] = malloc(sizeof(char) * (s + 1));
		if (toks[p] == NULL)
			return (NULL);
		r = 0;
		while ((str[q] != d_ch) && (str[q] != '\0'))
		{
			toks[p][r] = str[q];
			r++;
			q++;
		}
		toks[p][r] = '\0';
		p++;
		q++;
	}
	toks[p] = NULL;
	return (toks);
}