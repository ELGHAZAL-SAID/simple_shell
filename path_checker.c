#include "main.h"


/**
* path_checker - check if a cmd is exists
* @cmd: command to use
* Return: path
*/

char *path_checker(char *cmd)
{
	char **path_list = NULL, *tm, *tm2, *path_copy, *path = getenv("PATH");
	int i = 0;

	if (path == 0 || strlen(path) == 0)
		return (0);
	path_copy = malloc(sizeof(*path_copy) * (strlen(path) + 1));
	strcpy(path, path_copy);
	path_list = _strtok(path_copy, ":");
	while (path_list[i] != 0)
	{
		tm2 = strcat(path_list[i], "/");
		tm = strcat(tm2, cmd);
		if (access(tm, F_OK) == 0)
		{
			free(tm2), free(path_copy), free(path_list);
			return (tm);
		}
		free(tm);
		free(tm2);
		i++;
	}
	free(path_copy);
	free(path_list);
	return (0);
}

