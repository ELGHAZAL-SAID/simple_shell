#include "main.h"

/**
 * strcat_rmf - concatenate and ignoring the first character
 * @d: des string.
 * @s: src string.
 * Return: concatenated string.
 */
char *strcat_rmf(char *d, char *s)
{
	int x = 0, x1 = 0, xt = 0, y = 0;

	while (d[x] != '\0')
	{
		x++;
		xt++;
	}
	while (s[x1] != '\0')
	{
		x1++;
		xt++;
	}

	d = _realloc(d, x, sizeof(char) * xt + 1);

	y = 1;
	while (s[y] != '\0')
	{
		d[x] = s[y];
		x++;
		y++;
	}
	d[x] = '\0';

	return (d);
}

/**
 * set_env - concatenating string first before setting.
 * @e: environmental variable linked list.
 * @v_name: environmental variable name.
 * @d: directory path.
 * Return: 0 on success.
 **/
int set_env(link_t **e, char *v_name, char *d)
{
	int index = 0, i = 0;
	char *str;
	link_t *handler;

	str = strdup(v_name);
	str = strcat(str, "=");
	str = strcat(str, d);
	index = is_found_env(*e, v_name);

	handler = *e;
	while (i < index)
	{
		handler = handler->next;
		i++;
	}
	free(handler->value);
	handler->value = strdup(str);
	free(str);
	return (0);
}

/**
 * cd_home - change directory to home
 * @e: environment linked list to update PATH and OLDPWD
 * @cur:  current working directotry
 */
void cd_home(link_t *e, char *cur)
{
	char *hm = NULL;

	hm = env_getter("HOME", e);
	set_env(&e, "OLDPWD", cur);
	free(cur);
	if (access(hm, F_OK) == 0)
		chdir(hm);
	cur = NULL;
	cur = getcwd(cur, 0);
	set_env(&e, "PWD", cur);
	free(cur);
	free(hm);
}
/**
 * exec_cd - executes the cd
 * @e:  environment linked list to update PATH and OLDPWD
 * @cur:  current working directotry
 * @dir:  directory path to change to
 * @str:  the 1st argument to write out error
 * @num:  the line number to write out error
 * Return: 0 if success 2 if fail
 */
int exec_cd(link_t *e, char *cur, char *dir, char *str, int num)
{
	int x = 0;

	if (access(dir, F_OK) == 0)
	{
		set_env(&e, "OLDPWD", cur);
		free(cur);
		chdir(dir);
		cur = NULL;
		cur = getcwd(cur, 0);
		set_env(&e, "PWD", cur);
		free(cur);
	}
	else
	{
		cant_access_to_dir(str, num, e);
		free(cur);
		x = 2;
	}
	return (x);
}

/**
 * change_dir - change directory
 * @string: user's typed in command
 * @enviro: enviroment list to retrieve HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int change_dir(char **string, link_t *enviro, int num)
{
	char *cur = NULL, *dir = NULL;
	int count = 0;

	cur = getcwd(cur, 0);
	if (string[1] != NULL)
	{
		if (string[1][0] == '~')
		{
			dir = env_getter("HOME", enviro);
			dir = strcat_rmf(dir, string[1]);
		}
		else if (string[1][0] == '-')
		{
			if (string[1][1] == '\0')
				dir = env_getter("OLDPWD", enviro);
		}
		else
		{
			if (string[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = strcat(dir, "/");
				dir = strcat(dir, string[1]);
			}
			else
				dir = strdup(string[1]);
		}
		count = exec_cd(enviro, cur, dir, string[1], num);
		free(dir);
	}
	else
		cd_home(enviro, cur);
	free_arr(string);
	return (count);
}