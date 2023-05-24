#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


/**
 * struct link - linked list..
 * @value: the Value.
 * @next: point to the next..
 */
typedef struct link
{
	char *value;
	struct link *next;
} link_t;

/*prototype of the functions*/
int terminal(char **envirment);
void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize);
char *rm_space(char *str);
size_t read_line(char **str);
char **_strtok(char *str, char *delimiter);
char *rm_delm(char *str, char delimiter);
int token_size(char *str, char delimiter);
int token_len(char *str, int index, char delimiter);
int count_delimiters(char *str, char delimiter);
char **tokenize_string(char *str, char *delimiter);
int builtin_func(char **token, link_t *env, int number, char **cmd);
int env_shell(char **cmd, link_t *env);
link_t *env_shell_linked(char **env);
int _quit(char **str, link_t *env, int number, char **cmd);
void illegal_args_number(char *str, int c_n, link_t *env);
void is_not_found(char *str, int c_n, link_t *env);
void cant_access_to_dir(char *str, int c_n, link_t *env);

int change_dir(char **string, link_t *enviro, int num);
int exec_cd(link_t *e, char *cur, char *dir, char *str, int num);
void cd_home(link_t *e, char *cur);
int set_env(link_t **e, char *v_name, char *d);
char *strcat_rmf(char *d, char *s);

void free_arr(char **string);

void free_list(link_t *list);
int rm_node_int_at_index(link_t **head, int index);
size_t write_list(link_t *h);
link_t *add_node_end(link_t **head, char *str);

link_t *env_list(char **environ);
int print_env(char **string, link_t *environ);
int is_found_env(link_t *env, char *str);

void ctrl_c(int n);
void ctrl_D(int i, char *command, link_t *env);

void exit_c(char **string, link_t *environ);
int exe_ve(char **str, link_t *environ, int number);

char *strdup_c(char *string, int num);
char *env_getter(char *string, link_t *env);

char *digit_to_str(int number);

int setenv_(link_t **env, char **str);
int unsetenv_(link_t **env, char **str);

#endif
