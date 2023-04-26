#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/* prompt.c */
void print_prompt(void);

/* read_line.c */
char *read_line(void);

/* split_line.c */
char **split_line(char *line);

/* execute.c */
int execute(char **args);

/* shell_loop.c */
void shell_loop(void);

/* builtins.c */
int cd(char **args);
int help(char **args);
int exit_shell(char **args);
int env(char **args);

#endif
