#include "main.h"

/**
 * get_path - gets the value from PATH
 *
 * @env: var pointer
 *
 * Return: pathways for commands
 */
char **get_path(char **env)
{
	char **pathways = NULL, *pathvalue = NULL;
	unsigned int inte = 0;

	pathvalue = strtok(env[inte], "=");
	while (env[inte])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = tokening(pathvalue, ":");
			return (pathways);
		}
		inte++;
		pathvalue = strtok(env[inte], "=");
	}
	return (NULL);
}


/**
 * execute - function that executes a cmnd
 *
 * @command: cmnd pointer
 *
 * @name: shell nam
 *
 * @env: environ variables pointer
 * @cicles: num of executed cicles
 * Return: nthng
 */
void execute(char **command, char *name, char **env, int cicles)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		pathways = get_path(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_mem(pathways);
					free_exit(command);
				}
				return;
			}
		}
		msgerror(name, cicles, command);
		free_mem(pathways);
	}
}


/**
 * msgerror - Prints message error
 *
 * @name: shell nam
 * @cicles: num of cicles
 * @command: tokenized cmnd
 * Return: none
 */
void msgerror(char *name, int cicles, char **command)
{
	char cee;

	cee = cicles + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cee, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}


/**
 * print_env - prints all env variable.
 * @env: env variables pointer
 * return: none
 */
void print_env(char **env)
{
	size_t inte = 0, length = 0;

	while (env[inte])
	{
		length = _strlen(env[inte]);
		write(STDOUT_FILENO, env[inte], length);
		write(STDOUT_FILENO, "\n", 1);
		inte++;
	}
}
