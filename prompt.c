#include "main.h"

/**
 * w_out_cmt - remove comments
 *
 * @in: string
 * Return: input
 */
char *w_out_cmt(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
		in = _realloc(in, i, up_to + 1), in[up_to] = '\0';

	return (in);
}

/**
 * sh_lp - shell loop
 * @datash: data releving
 */

void sh_lp(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "$ ", 2);
		input = rd_ln(&i_eof);
		if (i_eof != -1)
		{
			input = w_out_cmt(input);
			if (input == NULL)
				continue;

			if (handle_s_err(datash, input) == 1)
			{
				datash->status = 2, free(input);
				continue;
			}
			input = repeat_var(input, datash);
			loop = sp_cmd(datash, input), datash->counter += 1;
			free(input);
		}
		else
			loop = 0, free(input);
	}
}
