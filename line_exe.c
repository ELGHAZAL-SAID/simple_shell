#include "main.h"

/**
 * ln_exe - get builtins and cmds
 *
 * @datash: data releving
 * Return: 1 if success.
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
