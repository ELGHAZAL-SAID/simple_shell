#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFFERSIZE 1024
#define TOK_BUFFERSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;


/**
 * struct data - struct containing relevant data on runtime
 * @av: vector
 * @input: command line
 * @args: tokens
 * @status: last status
 * @counter: counter
 * @_environ: environment
 * @pid: process ID
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - linked list
 * @separator: ; separator |
 * @next: next node
 * Description: linked list for storing separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - linked list
 * @line: command
 * @next: node
 * Description: linked list for storing cmd lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - linked list
 * @len_var: the variable length
 * @val: variable value
 * @len_val:  value length
 * @next: node
 * Description: linked list for storing variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s -  struct for cmd args.
 * @name: The name of the cmd builtin.
 * @f: pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

sep_list *a_end_node(sep_list **head, char sep);
void list_free(sep_list **head);
line_list *add_line_to_node(line_list **head, char *line);
void free_ln_in_list(line_list **head);

r_var *addrvarnode(r_var **head, int lvar, char *var, int lval);
void freervarlist(r_var **head);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

char *_strdup(const char *s);
int _strlen(const char *s);
int compare_c(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void reverse_s(char *s);

int char_rep(char *input, int i);
int err_s_o(char *input, int i, char last);
int char_ft(char *input, int *i);
void p_s_err(data_shell *datash, char *input, int i, int bool);
int handle_s_err(data_shell *datash, char *input);

char *w_out_cmt(char *in);
void sh_lp(data_shell *datash);

char *rd_ln(int *i_eof);

char *sw_ch(char *input, int bool);
void _a_node_(sep_list **head_s, line_list **head_l, char *input);
void _next_(sep_list **list_s, line_list **list_l, data_shell *datash);
int sp_cmd(data_shell *datash, char *input);
char **sp_ln(char *input);

void _handle_env(r_var **h, char *in, data_shell *data);
int _handle_vars(r_var **h, char *in, char *st, data_shell *data);
char *rp_inp(r_var **head, char *input, char *new_input, int nlen);
char *repeat_var(char *input, data_shell *datash);

void ln_br(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t ln_getter(char **lineptr, size_t *n, FILE *stream);

int ln_exe(data_shell *datash);

int _cdir_(char *path, int *i);
char *_which_shell(char *cmd, char **_environ);
int _is_exe_(data_shell *datash);
int handle_err_cmd(char *dir, data_shell *datash);
int exe_command(data_shell *datash);

char *_get_env_(const char *name, char **_environ);
int _env(data_shell *datash);

char *_copy_info_(char *name, char *value);
void _set_env_(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

void change_dir_dot(data_shell *datash);
void change_dir_to(data_shell *datash);
void change_dir_previous(data_shell *datash);
void change_dir_to_home(data_shell *datash);

int change_dir_to_shell(data_shell *datash);

int (*built_getter(char *cmd))(data_shell *datash);

int exit_shell(data_shell *datash);

int len_getter(int n);
char *_aux_itoa_(int n);
int _atoi(char *s);

char *_str_cat_cd_(data_shell *, char *, char *, char *);
char *err_getter_cd(data_shell *datash);
char *err_n_f(data_shell *datash);
char *err_quit_sh(data_shell *datash);

char *err_alias_getter(char **args);
char *_err_env_(data_shell *datash);
char *_err_syx_(char **args);
char *_err_per_(char **args);
char *_err_p_127(data_shell *datash);

int get_error(data_shell *datash, int eval);

void _get_sig_int_(int sig);

void ajigad(void);
void ajigad_a(void);
void ajigad_b(void);
void ajigad_c(void);
void ajigad_d(void);

void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

int get_help(data_shell *datash);

#endif
