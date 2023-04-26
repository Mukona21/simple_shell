#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

void _puts(char *str);
int _putchar(char c);
int _strlen(char *s);
char *concat_all(char *name, char *sep, char *value);
char *_strdup(char *str);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;

/**
 * struct list_path - Linked list containing path dir
 * @dir: dir in path
 * @t: pointer to next nod
 */
typedef struct list_path
{
	char *dir;
	struct list_path *t;
} list_path;

list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_getenv(const char *name);
char *_which(char *filename, list_path *head);

/**
 * struct mybuild - pointer to function with corresponding build cmnd
 * @name: buildin cmnd
 * @func: execute the buildin cmnd
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

int _atoi(char *s);
void (*check_buildin(char **arguments))(char **arguments);
void env(char **arv);
void exitt(char **arv);
void _unsetenv(char **arv);
void _setenv(char **arv);


void freearv(char **arv);
void free_list(list_path *head);

#endif

