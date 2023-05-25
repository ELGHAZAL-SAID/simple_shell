#include "main.h"

/**
 * char_rep - num of the chars.
 *
 * @input: string
 * @i: index
 * Return: repet.
 */
int char_rep(char *input, int i)
{
	if (*(input - 1) == *input)
		return (char_rep(input - 1, i + 1));

	return (i);
}

/**
 * err_s_o - find styx err.
 *
 * @input: string
 * @i: idx
 * @last: last char.
 * Return: index or 0.
 */
int err_s_o(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (err_s_o(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = char_rep(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = char_rep(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (err_s_o(input + 1, i + 1, *input));
}

/**
 * char_ft - find idx of the first char.
 *
 * @input: string
 * @i: idx
 * Return: 1 or 0.
 */
int char_ft(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * p_s_err - write if err occurrs.
 *
 * @datash: data
 * @input: string
 * @i: idx error
 * @bool: control error
 * Return: nothing.
 */
void p_s_err(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = _aux_itoa_(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * handle_s_err - find and print a syntax error
 *
 * @datash: data.
 * @input: .string
 * Return: 1 or 0.
 */
int handle_s_err(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = char_ft(input, &begin);
	if (f_char == -1)
	{
		p_s_err(datash, input, begin, 0);
		return (1);
	}

	i = err_s_o(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		p_s_err(datash, input, begin + i, 1);
		return (1);
	}

	return (0);
}
