#include "main.h"

/**
 * print_environ - Prints all environmental variables.
 *
 * @environ: Environmental variables array.
 *
 * Return: Nothing.
 */
void print_environ(char **environ)
{
	size_t i = 0, len = 0;

	while (environ[i])
	{
		len = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * exec_cmd - Executes a command.
 *
 * @command: Command as an array of strings.
 *
 * @shell_name: Name of the shell.
 *
 * @env: Environmental variables array.
 *
 * @cycles: Number of executed cycles.
 *
 * Return: Nothing.
 */
void exec_cmd(char **command, char *shell_name, char **env, int cycles)
{
	char **dirs = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (strcmp(command[0], "env") != 0)
		print_environ(env);

	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(shell_name);
			free(command);
		}
	}
	else
	{
		dirs = get_path_dirs(env);
		while (dirs[i])
		{
			full_path = concat_path(dirs[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(shell_name);
					free(dirs);
					free(command);
				}
				return;
			}
		}
		print_cmd_not_found_err(shell_name, cycles, command);
		free(dirs);
	}
}

/**
 * print_cmd_not_found_err - Prints an error message for a command not found.
 *
 * @shell_name: Name of the shell.
 *
 * @cycles: Number of executed cycles.
 *
 * @command: Tokenized command.
 *
 * Return: None.
 */
void print_cmd_not_found_err(char *shell_name, int cycles, char **command)
{
	char cycle_char;

	cycle_char = cycles + '0';
	write(STDOUT_FILENO, shell_name, strlen(shell_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cycle_char, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * get_path_dirs - Retrieves directories from the PATH environment variable.
 *
 * @env: Environmental variables array.
 *
 * Return: Array of strings representing directories in the PATH variable.
 */
char **get_path_dirs(char **env)
{
	char **dirs = NULL, *path_val = NULL;
	unsigned int i = 0;

	path_val = strtok(env[i], "=");
	while (env[i])
	{
		if (strcmp(path_val, "PATH") == 0)
		{
			path_val = strtok(NULL, "\n");
			return (dirs);
		}
		i++;
		path_val = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * concat_path - Concatenates a directory path with a command.
 *
 * @directory: Directory path.
 *
 * @command: Command.
 *
 * Return: Concatenated path.
 */
char *concat_path(const char *directory, const char *command)
{
	size_t dir_len = strlen(directory);
	size_t cmd_len = strlen(command);
	char *path = malloc(path_len);

	if (path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	strcpy(path, directory);
	strcat(path, "/");
	strcat(path, command);

	return (path);
}

