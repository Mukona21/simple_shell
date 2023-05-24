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
int main(int argc, char **argv, char **envp);
void handle_signal(int signal);
void display_prompt(void);
void exit_shell(char **command);
void handle_eof(char *input_buffer);

/*	 pid.c	*/
int changeDirectory(const char *path);
void spawnChildProcess(char **command, char *shellNam, char **env, int cycles);


/*        exeenv.c       */
void print_environ(char **environ);
void exec_cmd(char **command, char *shell_name, char **env, int cycles);


/*	token.c	*/
void freeTokens(char **tokens, int count);
char **tokenizeString(const char *str, const char *delimiter);
void print_cmd_not_found_err(char *shell_name, int cycles, char **command);
char **get_path_dirs(char **env);

/*	free_memry.c	*/
void freeMemory(char **strings);
void freeMemoryAndExit(char **strings);

/*	 functions.c	*/
int stringToInteger(char *string);
unsigned int stringLength(char *str);
char *stringCopy(char *destination, char *source);
char *stringConcatenate(char *destination, char *source);
int stringCompare(char *str1, char *str2);

#endif /* MAIN_H*/
