#include "main.h"

/**
 * strcat_rmf - concatenate without the first char.
 * @d: destination string.
 * @s: source string.
 * Return: the whole string.
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
 * set_env - concatenating string and set it.
 * @e: var environ.
 * @v_name: var environ name.
 * @d: the path.
 * Return: always 0.
 **/
int set_env(link_t **e, char *v_name, char *d)
{
	int index = 0, i = 0;
	char *str;
	link_t *handler;

	str = _strdup(v_name);
	str = _strcat(str, "=");
	str = _strcat(str, d);
	index = is_found_env(*e, v_name);

	handler = *e;
	while (i < index)
	{
		handler = handler->next;
		i++;
	}
	free(handler->value);
	handler->value = _strdup(str);
	free(str);
	return (0);
}

/**
 * cd_home - go to home.
 * @e: environment.
 * @cur:  current dir.
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
 * exec_cd - exe the cd command.
 * @e:  environment.
 * @cur:  current dir
 * @dir:  dir path
 * @str:  string.
 * @num:  0 or 2.
 *
 * Return: return.
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
 * change_dir - change dir.
 * @string: the command as string.
 * @enviro: enviroment.
 * @num: nulber of the string written.
 * Return: 0 or 2.
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
				dir = _strcat(dir, "/");
				dir = _strcat(dir, string[1]);
			}
			else
				dir = _strdup(string[1]);
		}
		count = exec_cd(enviro, cur, dir, string[1], num);
		free(dir);
	}
	else
		cd_home(enviro, cur);
	free_arr(string);
	return (count);

}
