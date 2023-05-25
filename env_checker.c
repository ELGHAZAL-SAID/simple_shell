#include "main.h"

/**
 * _handle_env - handle env.
 *
 * @h: head node.
 * @in: string
 * @data: data
 * Return: nothing
 */
void _handle_env(r_var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				addrvarnode(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	addrvarnode(h, j, NULL, 0);
}

/**
 * _handle_vars - handle variables.
 *
 * @h: head node.
 * @in: string
 * @st: last status shell
 * @data: data
 * Return: nothing
 */
int _handle_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				addrvarnode(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				addrvarnode(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				addrvarnode(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				addrvarnode(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				addrvarnode(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				addrvarnode(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				addrvarnode(h, 0, NULL, 0);
			else
				_handle_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * rp_inp - replace str to var.
 *
 * @head: head node
 * @input: string
 * @new_input: new string.
 * @nlen: new len
 * Return: new string.
 */
char *rp_inp(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * repeat_var - replace a var.
 *
 * @input: string
 * @datash: data
 * Return: new string.
 */
char *repeat_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = _aux_itoa_(datash->status);
	head = NULL;

	olen = _handle_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = rp_inp(&head, input, new_input, nlen);

	free(input);
	free(status);
	freervarlist(&head);

	return (new_input);
}
