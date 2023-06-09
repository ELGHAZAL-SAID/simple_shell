#include "main.h"

/**
 * _str_cat_cd_ - concatenating the message for cd err
 *
 * @datash: data relevant
 * @msg: message
 * @error: output
 * @ver_str: lines
 * Return: error
 */
char *_str_cat_cd_(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-', illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag), free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * err_getter_cd - error message
 * @datash: data
 * Return: Error
 */
char *err_getter_cd(data_shell *datash)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = _aux_itoa_(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal argument ";
		len_id = 2;
	}
	else
	{
		msg = ": can't change dir to ";
		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = _str_cat_cd_(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * err_n_f - error message for cmd
 * @datash: data
 * Return: Error
 */
char *err_n_f(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _aux_itoa_(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]), _strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": "), _strcat(error, datash->args[0]);
	_strcat(error, ": not found\n"), _strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * err_quit_sh - error message to exit in err_quit_sh
 * @datash: data
 *
 * Return: Error
 */
char *err_quit_sh(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _aux_itoa_(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]), _strcat(error, ver_str);
	_strcat(error, ": "), _strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]), _strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
