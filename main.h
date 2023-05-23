#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

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
	void (*func)(char **cmd)
} get_func;

/*prototype of the functions*/
void display();
void print_err();
void rm_newline(char *cmd);
void rm_comment(char *cmd);

/*global variables*/
extern char **environ;
extern char *ln;
extern char *cmd;
extern char *shell;
extern int st;

#endif
