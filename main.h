#ifndef SHELL_H
#define SHELL_H

/*header file*/
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*macro*/
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define BUFSIZE 256
#define PROMPT "$ "

/*builtin*/
int handle_builtin(sh_t *data);
int display_help(sh_t *data);
int abort_program(sh_t *data __attribute__((unused)));
int change_directory(sh_t *data);
int _builtin(const void *data);

/*tool1*/
void *fill_array(void *arr, int element, size_t length);
char *_getenv(const char *name);
void reverse_array(char *arr, size_t length);
void signal_handler(int signid);

/*tool2*/
int intlen(int n);
int write_history(sh_t *data __attribute__((unused)));
char *_itoa(unsigned int num);
int _atoi(char *s);
int print_error(sh_t *data);

/*string1*/
int _isalpha(int p);
char *_strcpy(char *des, const char *src);

/*string2*/
char *_strdup(char *string);
int _strlen(char *string);
int _strcmp(char *str1, char *str2);
char *_strchr(char *string, char q);
char *_strcat(char *frst, char *sec);

/*memc*/
char *_memorycpy(char *des, char *Source, unsigned int num);
char *_memoryset(char *r, char bytes, unsigned int num);
void *_realloc(void *poi, unsigned int old_s, unsigned int new_s);
int freedata(sh_t *data);

/*path*/
int convert_to_short_form(sh_data_t *data);
int validate_path(PathD *newPathdata);

/*Global variable*/
extern char **environ;

/*Struct*/

/**
 * struct sh_data - data structure
 * @args: token arguments
 * @line: line in the input
 * @cmd: command
 * @index: the index command
 * @env: environ
 *
 *Description: all the variables needed for program to run
 */
 typedef struct sh_data
 {
    char *env
 }

 #endif