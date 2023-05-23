#include "main.h"

/**
 * is_found - is a commande found.
 * @cmd: The commande.
 *
 * Return: return the path.
 */
char *is_found(char *cmd)
{
	char **arr_p = 0;
	char *c, *c2, *cp_p, *p;
	int i = 0;

	p = getenv("PATH");
	if (p == NULL || strlen(p) == 0)
		return (0);
	cp_p = malloc(sizeof(cp_p) * (strlen(p) + 1));
	strcpy(p, cp_p);
	arr_p = _strtok(cp_p, ":");
	while (arr_p != 0)
	{
		c2 = strcat(arr_p[i], "/");
		c = strcat(c2, cmd);
		if (access(c, F_OK) == 0)
		{
			free(c2);
			free(arr_p);
			free(cp_p);
			return (c);
		}
		free(c);
		free(c2);
		i++;
	}
	free(cp_p);
	free(arr_p);
	return (0);
}
