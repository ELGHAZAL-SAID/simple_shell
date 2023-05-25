#include "main.h"

/**
 * ln_exe - finds builtins and commands
 *
 * @datash: data relevant (args)
 * Return: 1 on success.
 */
int ln_exe(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = built_getter(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (exe_command(datash));
}
