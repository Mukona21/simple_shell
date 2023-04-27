#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct error_msg - An structure for each error message
 *
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length.
 */
typedef struct error_msg
{
	int ecode;
	char *msg;
	int  size;
} error_msg_t;

/**
 * struct built_s - Builtings commands
 * @command: command name.
 * @f: function to call.
 *
 * Description: Longer description
 */
typedef struct builtin_s
{
	char *command;
	void (*func)(char **);
} builtin_t;


/**
 * struct history - An structure for each command readed
 *
 * @id_h: error code
 * @comms: Commands
 * @prev: Previous element
 * @next: Next element
 */

typedef struct history
{
	unsigned int id_h;
	char *comms;
	struct history *prev;
	struct history *next;
} history_t;

/**
 * struct command_s - An structure for each command
 *
 * @command: command with arguments.
 * @next: pointer to next command.
 */
typedef struct command_s
{
	char **command;
	struct command_s *next;
	void (*func)(char **);
} command_t;

/* Command Utilities*/
command_t *new_command_node(char *shell_name);
int add_token_to_command(char *shell_name,
		command_t *cmd_node, size_t index, char *token);

/*Error Handle*/
void error_handler(char *program_name, int error_code);

/*shell functions*/
int execute_command(char *command, char **args, char **env);
int execute_builtin(char *command, char **env);
static int _exec_command(const char *cmd, char *const argv[],
			char *const envp[]);

/*utilities*/
char *find_path(char **environ);
void print_env(char **environ);
char *_which(char *path, char *command);
int _fork_command(command_t *cmd, const char *path, char *const env[]);
int add_history_node(history_t **head, char *str);
void free_history_list(history_t *head);
void exit_shell(char **env);

#endif
