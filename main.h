#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/**
 * struct command_s - builtin function structure
 * @name: name of function
 * @func: function difinition
 */
typedef struct command_s
{
	char *name;
	int (*func)(char **);
} command_t;

/* prototypes */
void print_prompt(void);
void prompt(char **envp);
char *read_command(void);
char *read_line(void);
char **tokenize(char *line);
int exec_cmd(char **args, char **envp);
char *search_path(char *command, char *fullpath, char *path);
void errors(int error);
void print_error(const char *progname, char *msg);
char **allocate_tokens(int size);
char **reallocate_tokens(char **tokens, int *size);
int execute_command(char *command, char **argv, char **envp, char *path);
void _exec(char *full_path, pid_t child_pid,
		int status, char **argv, char **envp);


/* utility functions prototypes*/
void _puts(char *str);
int _putchar(char c);
size_t _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

/* Builtin func */
int own_exit(char **);
int own_env(char **);

#endif /* MAIN_H */
