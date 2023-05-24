#include "main.h"
/**
 * count_delimiters - returns the number of delimiters in a string
 * @str: string to count delimiters from
 * @delimiter: delimiter character
 * Return: number of delimiters
 */
int count_delimiters(char *str, char delimiter)
{
	int count = 0;

	while (*str)
	{
		if (*str == delimiter)
			count++;
		str++;
	}

	return count;
}

/**
 * tokenize_string - tokenizes a string, even consecutive delimiters with empty strings
 * @str: string to tokenize
 * @delimiter: delimiter string
 * Return: array of tokens
 */
char **tokenize_string(char *str, char *delimiter)
{
	int buffer_size = 0, token_count = 0, str_length = 0;
	char **tokens = NULL;
	char delimiter_char = delimiter[0];

	buffer_size = count_delimiters(str, delimiter_char);
	tokens = malloc(sizeof(char *) * (buffer_size + 2));

	if (tokens == NULL)
		return NULL;

	str_length = strlen(str);

	int index = 0, token_index = 0, token_length = 0;

	while (index < str_length)
	{
		token_length = token_strlen(str, index, delimiter_char);
		tokens[token_index] = malloc(sizeof(char) * (token_length + 1));

		if (tokens[token_index] == NULL)
		{
			free_tokens(tokens, token_index);
			return NULL;
		}

		int char_index = 0;

		while ((str[index] != delimiter_char) && (str[index] != '\0'))
		{
			tokens[token_index][char_index] = str[index];
			char_index++;
			index++;
		}

		tokens[token_index][char_index] = '\0';
		token_index++;
		index++;
	}

	tokens[token_index] = NULL;
	return tokens;
}
