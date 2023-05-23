#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/*constants macros*/
#define EXTERN_CMD 1
#define INTERN_CMD 2
#define PATH_CMD 3
#define INV_CMD -1

/*functions macros*/
#define _min(a, b) (((a) < (b)) ? (a) : (b))

/**
 * struct func - maping command name.
 * @cmd: the command.
 * @func: executes the command.
 */
typedef struct func
{
	char *cmd;
	void (*func)(char **cmd);
} get_func;

/*prototype of the functions*/
void display(void);
void print_err(void);
void rm_newline(char *cmd);
void rm_comment(char *cmd);
void _quit(char **token);
void env_shell(char **token __attribute__((unused)));
void clean_shell(void);
int parsing_cmd(char *cmd);
char *path_checker(char *cmd);
void ready_cmd(char **buffer, int cmd_type);
void exec_cmd(char **token, int cmd_type);
char *is_found(char *cmd);
void (*func_geter(char *cmd))(char **);
char **_strtok(char *str, char *delimiter);
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s);
char *_strtok_(char *string, char *delimiter, char **saved_ptr);

/*global variables*/
extern char **environ;
extern char *ln;
extern char **cmd;
extern char *shell;
extern int st;


#endif
