#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

/*prototypes*/

char **get_path_dirs(char **en);
void execute_cmd(char **cmd, char *name, char **env, int cycles);
void message_error(char *name, int cycles, char **cmd);
void print_environ(char **env);
int string_compare(char *str1, char *str2);
unsigned int string_len(char *str);
char *string_copy(char *destination, char *source);
char *string_con(char *destination, char *source);
int str_int(char *string);
int main(int in_num_args, char **in_arry_args, char **envp);
void handle_signal(int prompt_handle);
void exit_shell(char **cmd);
void handle_EOF(char *buffer_string);
void free_mem_exit(char **cmd);
void free_memory(char **cmd);
int change_directory(const char *path);
void child_pro(char **cmd, char *name, char **en, int cycles);
char **tokenizer(char *buffer, const char *string);


#endif /*MAIN_H*/
