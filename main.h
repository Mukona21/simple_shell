#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* aux1error.c */
char *strcat_cd_error(shell_data *data, char *msg, char *error_msg, char *counter_str);
char *get_cd_error(shell_data *data);
char *not_found_error(shell_data *data);

/* error2.c */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);


/* error1.c */
int get_error(data_shell *data, int eval);

/* sigint1.c */
void handle_sigint(int signal_num);

/* help3.c */
void print_env_help(void);
void print_setenv_help(void);
void print_unsetenv_help(void);
void print_general_help(void);
void print_exit_help(void);

/* help2.c */
void print_help_info(void);
void print_alias_help(void);
void print_cd_help(void);

/* help1.c */
int display_help(shell_data *shell_data);

#endif
