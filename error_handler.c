#include "main.h"

/**
 * is_not_found - handle shell error.
 * @str: the string.
 * @c_n: number of the string command.
 * @env: envirement.
 * Return: nothing.
 */
void is_not_found(char *str, int c_n, link_t *env)
{
	int cnt = 0;
	char *shell, *num;

	shell = env_getter("_", env);
	while (shell[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, shell, cnt);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = digit_to_str(c_n);
	cnt = 0;
	while (num[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, num, cnt);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, str, cnt);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cant_access_to_dir - handle error.
 * @str: the string.
 * @c_n: number of the string command.
 * @env: envirement.
 * Return: nothing.
 */
void cant_access_to_dir(char *str, int c_n, link_t *env)
{
	int cnt = 0;
	char *shell, *num;

	shell = env_getter("_", env);
	while (shell[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, shell, cnt);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = digit_to_str(c_n);
	cnt = 0;
	while (num[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, num, cnt);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, str, cnt);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * illegal_args_number - handle shell error.
 * @str: the string.
 * @c_n: number of the string command.
 * @env: envirement.
 * Return: nothing.
 */
void illegal_args_number(char *str, int c_n, link_t *env)
{
	int cnt = 0;
	char *shell = NULL, *num = NULL;

	shell = env_getter("_", env);
	while (shell[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, shell, cnt);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = digit_to_str(c_n);
	cnt = 0;
	while (num[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, num, cnt);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, str, cnt);
	write(STDOUT_FILENO, "\n", 1);
}
