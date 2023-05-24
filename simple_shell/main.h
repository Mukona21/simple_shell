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
void handleSIGINT(int signal);
void displayPrompt(void);
void exitShell(char **command);

/*	 pid.c	*/

void createChildProcess(char **cmnd, char *shellNam, char **enviro, int cycle);
int changeDirectory(const char *path);

/*        exe_env.c       */

void printEnvironmentVariables(char **env);
void executeCommand(char **command, char *shellName, char **env, int cycles);
void printCommandNotFoundError(char *shellName, int cycles, char **command);
char **getExecutablePaths(char **env);



/*	token.c	*/
char **tokenizeString(const char *str, const char *delimiter);

/*	memory.c	*/

void freeMemory(char **command);
void cleanUpAndExit(char **command);

/*	 functions.c	*/

unsigned int string_length(char *str);
int string_compare(char *str1, char *str2);
char *string_copy(char *dest, char *src);
int string_to_integer(char *str);
char *string_concatenate(char *dest, const char *src);


#endif /* MAIN_H*/
