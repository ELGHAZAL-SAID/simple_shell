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


void rm_newline(char *cmd);
void rm_comment(char *cmd);
void _quit(char **token);
void env_shell(char **token __attribute__((unused)));
extern void clean_shell(void);
int parsing_cmd(char *cmd);
char *path_checker(char *cmd);
extern void ready_cmd(char **buffer, int cmd_type);
void exec_cmd(char **token, int cmd_type);
char *is_found(char *cmd);
void (*func_geter(char *cmd))(char **);
void ctrl_c_handler(int signum);
char **_strtok(char *str, char *delimiter);
char *_strtok_(char *string, char *delimiter, char **saved_ptr);
char *_getenv(char *name);


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
void cant_eccess_to_dir(char *str, int c_n, link_t *env);

int change_dir(char **string, link_t *enviro, int num);
int exec_cd(link_t *e, char *cur, char *dir, char *str, int num);
void cd_home(link_t *e, char *cur);
int set_env(link_t **e, char *v_name, char *d);
#endif
