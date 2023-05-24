#include "main.h"

/**
 * printEnvironmentVariables - Prints all environment variables.
 *
 * @env: Array of environment variables.
 *
 * Return: Nothing.
 */
void printEnvironmentVariables(char **env)
{
	size_t index = 0;
	size_t length = 0;

	while (env[index])
	{
		length = _strlen(env[index]);
		write(STDOUT_FILENO, env[index], length);
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}

/**
 * executeCommand - Executes a command.
 *
 * @command: Command to be executed.
 * @shellName: Name of the shell.
 * @env: Array of environment variables.
 * @cycles: Number of executed cycles.
 *
 * Return: Nothing.
 */
void executeCommand(char **command, char *shellName, char **env, int cycles)
{
	char **executablePaths = NULL;
	char *fullPath = NULL;
	struct stat st;
	unsigned int index = 0;

	if (_strcmp(command[0], "env") != 0)
		printEnvironmentVariables(env);

	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(shellName);
			freeResources(command);
		}
	}
	else
	{
		executablePaths = getExecutablePaths(env);
		while (executablePaths[index])
		{
			fullPath = _strcat(executablePaths[index], command[0]);
			index++;
			if (stat(fullPath, &st) == 0)
			{
				if (execve(fullPath, command, env) < 0)
				{
					perror(shellName);
					freeResources(executablePaths);
					freeResources(command);
				}
				return;
			}
		}
		printCommandNotFoundError(shellName, cycles, command);
		freeResources(executablePaths);
	}
}

/**
 * printCommandNotFoundError - Prints an error message when cmnd is not found.
 *
 * @shellName: Name of the shell.
 * @cycles: Number of cycles.
 * @command: Tokenized command.
 *
 * Return: Nothing.
 */
void printCommandNotFoundError(char *shellName, int cycles, char **command)
{
	char cycleCount = cycles + '0';

	write(STDOUT_FILENO, shellName, _strlen(shellName));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cycleCount, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * getExecutablePaths - Retrieves executable paths from the PATH env variable.
 *
 * @env: Array of environment variables.
 *
 * Return: Array of strings representing the executable paths.
 */
char **getExecutablePaths(char **env)
{
	char **paths = NULL;
	char *pathEnv = NULL;
	unsigned int index = 0;

	while (env[index])
	{
		if (_strcmp(env[index], "PATH") == 0)
		{
			pathEnv = strtok(env[index], "=");
			pathEnv = strtok(NULL, "\n");
			paths = tokenize(pathEnv, ":");
			return (paths);
		}
		index++;
	}

	return (NULL);
}
