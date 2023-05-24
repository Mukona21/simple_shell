#include "main.h"

/**
 * get_path_dirs - gets the value from env PATH direction
 *
 * @en: environmental variables pointer
 *
 * Return: pathway for commands in directories
 */
char **get_path_dirs(char **en)
{
	char **path_way = NULL, *path_value = NULL;
	unsigned int i = 0;

	path_value = strtok(en[i], "=");
	while (en[i])
	{
		if (string_compare(path_value, "PATH"))
		{
			path_value = strtok(NULL, "\n");
			pathway = tokenizer(path_value, ":");
			return (pathway);
		}
		i++;
		path_value = strtok(en[i], "=");
	}
	return (NULL);
}


/**
 * execute_cmd - function that executes a command
 *
 * @cmd: command pointer of strings
 *
 * @name: name of the shell
 *
 * @env: environmental variables pointer
 * @cycles: number of executed cycles
 * Return: nothing
 */
void execute_cmd(char **cmd, char *name, char **env, int cycles)
{
	char **path_ways = NULL, *fullpath = NULL;
	struct stat pr;
	unsigned int i = 0;

	if (string_compare(cmd[0], "env") != 0)
		print_environ(env);
	if (stat(cmd[0], &pr) == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			perror(name);
			free_exit_exit(cmd);
		}
	}
	else
	{
		path_ways = get_path_dirs(env);
		while (path_ways[i])
		{
			fullpath = string_con(path_ways[i], cmd[0]);
			i++;
			if (stat(fullpath, &pr) == 0)
			{
				if (execve(fullpath, cmd, env) < 0)
				{
					perror(name);
					free_memory(path_ways);
					free_mem_exit(cmd);
				}
				return;
			}
		}
		message_error(name, cycles, cmd);
		free_memory(path_ways);
	}
}


/**
 * message_error - Prints messages not found
 *
 * @name: shell name
 * @cycles: number of cycles
 * @cmd: tokenized cmnd
 * Return: nothing
 */
void message_error(char *name, int cycles, char **cmd)
{
	char cycle_char;

	cycle_char = cycles + '0';
	write(STDOUT_FILENO, name, string_len(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cycle_char, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd[0], string_len(cmd[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}


/**
 * print_environ - print all enviromental variable.
 * @env: enviromental variables pointer
 * return: nothing
 */
void print_environ(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = string_len(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
