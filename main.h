#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*     main.c      */

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);

/*	 child_pid.c	*/

void create_child(char **command, char *name, char **env, int cicles);
int change_dir(const char *path);

/*        execute_env.c       */

void execute(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **get_path(char **env);
void msgerror(char *name, int cicles, char **command);

/*	str_token.c	*/

char **tokening(char *buffer, const char *s);

/*	free_memory.c	*/

void free_mem(char **command);
void free_exit(char **command);

/*	 funct.c	*/

int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);


#endif /* MAIN_H*/
