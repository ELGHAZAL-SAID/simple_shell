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
#endif
