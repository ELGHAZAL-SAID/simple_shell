#include "main.h"

/**
 * change_dir_to_shell - change the curr working dir.
 *
 * @datash: data.
 * Return: always 1.
 */
int change_dir_to_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		change_dir_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		change_dir_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		change_dir_dot(datash);
		return (1);
	}

	change_dir_to(datash);

	return (1);
}
