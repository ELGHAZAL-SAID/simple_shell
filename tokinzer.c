#include "main.h"

/**
 * sw_ch - swapping '|' with & for non_printed chars
 *
 * @input: input
 * @bool: type_swap
 * Return: string swapped
 */
char *sw_ch(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * _a_node_ - separators and cmd lines
 *
 * @head_s: head_s
 * @head_l: head_s
 * @input: input
 * Return: no
 */
void _a_node_(sep_list **head_s, line_list **head_l, char *input)
{
	int i;
	char *line;

	input = sw_ch(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			a_end_node(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			a_end_node(head_s, input[i]);
			i++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = sw_ch(line, 1);
		add_line_to_node(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * _next_ - to the next cmd line
 *
 * @list_s: separator
 * @list_l: command
 * @datash: data
 * Return: no
 */
void _next_(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * sp_cmd - splits cmd lines
 *
 * @datash: data
 * @input: input
 * Return: 0
 */
int sp_cmd(data_shell *datash, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	_a_node_(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = sp_ln(datash->input);
		loop = ln_exe(datash);
		free(datash->args);

		if (loop == 0)
			break;

		_next_(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	list_free(&head_s);
	free_ln_in_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * sp_ln - tokenizes the input string
 *
 * @input: input.
 * Return: splitted string.
 */
char **sp_ln(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFFERSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFFERSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
