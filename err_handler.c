#include "main.h"

/**
 * get_error - error getter.
 * @datash: data structure.
 * @eval: err value
 * Return: err.
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = _err_env_(datash);
		break;
	case 126:
		error = _err_p_127(datash);
		break;
	case 127:
		error = err_n_f(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = err_quit_sh(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = err_getter_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
