#include "main.h"

/**
 * _exec_command - executes the given command with the given arguments
 * @cmd: the full path of the command to execute
 * @argv: an array of strings containing the arguments to the command
 * @envp: an array of strings containing the environment variables
 *
 * Return: 0 on success, -1 on failure
 */
static int _exec_command(const char *cmd, char *const argv[],
			char *const envp[]);

/**
 * _fork_command - forks a new process to execute the given command
 * @cmd: pointer to a struct containing the command and arguments
 * @path: the path to search for the command
 * @env: an array of strings containing the environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int _fork_command(command_t *cmd, const char *path, char *const env[])
{
	char cmd_path[1024];

	if (!path || !cmd->command[0])
	return (-1);

	if (_find_command(cmd->command[0], path, cmd_path) == -1)
	return (-1);

	if (_exec_command(cmd_path, cmd->command, env) == -1)
	return (-1);

	return (0);
}

/**
 * _find_command - searches for a command in the given path
 * @cmd: the name of the command to search for
 * @path: the path to search for the command
 * @buffer: a buffer to store the full path of the command
 *
 * This function searches for the given command in the specified path and
 * returns the full path to the command in the given buffer.
 *
 * Return: 0 on success, -1 on failure
 */
static int _find_command(const char *cmd, const char *path, char *buffer);

{
	char *token, *p, *saveptr;

	p = strdup(path);
	if (!p)
	return (-1);

	token = strtok_r(p, ":", &saveptr);
	while (token)
	{
	snprintf(buffer, 1024, "%s/%s", token, cmd);
	if (access(buffer, X_OK) == 0)
	{
		free(p);
		return (0);
	}
	token = strtok_r(NULL, ":", &saveptr);
	}

	free(p);
	return (-1);
}

static int _exec_command(const char *cmd, char *const argv[],
			char *const envp[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	return (-1);

	if (pid == 0)
	{
		execve(cmd, argv, envp);
	exit(EXIT_FAILURE);
	}

	if (waitpid(pid, &status, 0) == -1)
	return (-1);

	return (0);
}
