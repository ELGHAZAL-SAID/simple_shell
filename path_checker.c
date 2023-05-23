#include "main.h"


/**
* path_checker - check if a cmd is exists
* @cmd: command to use
* Return: path
*/

char *path_checker(char *cmd)
{
	char **path_list = NULL;
	char *tm = NULL, *tm2 = NULL;
	char *path_copy = NULL;
	char *path = _getenv("PATH");
	int i = 0;

	if (path == NULL || strlen(path) == 0)
		return (NULL);
	path_copy = malloc(sizeof(*path_copy) * (strlen(path) + 1));
	strcpy(path, path_copy);
	path_list = _strtok(path_copy, ":");
	while (path_list[i] != NULL)
	{
		tm2 = strcat(path_list[i], "/");
		tm = strcat(tm2, cmd);
		if (access(tm, F_OK) == 0)
		{
			free(tm2);
			free(path_copy);
			free(path_list);
			return (tm);
		}
		free(tm);
		free(tm2);
		i++;
	}
	free(path_copy);
	free(path_list);
	return (NULL);
}

