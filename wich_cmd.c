#include "main.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell
 * @env: environmental variable
 * Return: a copy of fleshed out command
 */
char *_which_cmd(char *str, link_t *env)
{
	char *pth, *cat = NULL, **toks;
	int x = 0;

	pth = env_getter("PATH", env);
	toks = tokenize_string(pth, ":");
	free(pth);

	x = 0;
	while (toks[x] != NULL)
	{
		if (toks[x][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[x]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_arr(toks);
			return (cat);
		}
		free(cat);
		x++;
	}
	free_arr(toks);
	return (str);
}