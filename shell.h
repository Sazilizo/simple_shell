#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

int check_builtIn(char **cmd, char *buf);
void print_prompt(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);
void execute_cmd(char *cm, char **cmd);
void print_env(void);
char *find_path(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);


void free_buffers(char **buffer);

extern struct builtin
{
	char *env;
	char *exit;
} builtin;

extern struct info
{
	int final_exit;
	int ln_count;
} info;

extern struct flags
{
	bool interactive;
} flags;


#endif

