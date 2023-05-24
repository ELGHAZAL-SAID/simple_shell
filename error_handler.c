#include "main.h"

/**
 * not_found - write shell error
 * @str: user's typed command
 * @c_n: nth user's typed command
 * @env: bring in enviroment variables linked list to write shell name
 */
void is_not_found(char *str, int c_n, link_t *env)
{
	int cnt = 0;
	char *shell, *num;

	shell = get_env("_", env);
	while (shell[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, shell, cnt);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
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
 * cant_cd_to - write error
 * @str: user's typed argument after the cmd cd
 * @c_n: nth user's typed command
 * @env: bring in enviroment variables linked list to write shell name
 */
void cant_eccess_to_dir(char *str, int c_n, link_t *env)
{
	int cnt = 0;
	char *shell, *num;

	shell = get_env("_", env);
	while (shell[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, shell, cnt);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
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
 * illegal_number - write shell error
 * @str: typed argument after the exit
 * @c_n: nth typed command
 * @env: get enviroment variables to write shell name
 */
void illegal_args_number(char *str, int c_n, link_t *env)
{
	int cnt = 0;
	char *shell = NULL, *num = NULL;

	shell = get_env("_", env);
	while (shell[cnt] != '\0')
		cnt++;
	write(STDOUT_FILENO, shell, cnt);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
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