#include "main.h"

/**
 * find_path - Finds the value of the PATH environment variable.
 * @environ: Pointer to the environment variable
 * Return: A pointer to a string containing the value of the PATH variable.
 */
char *find_path(char **environ)
{
	char *path_value = NULL;

	if (!environ)
		return (NULL);

	while (*environ)
	{
		if (_strncmp(*environ, "PATH=", 5) == 0)
		{
			path_value = *environ + 5;
			break;
		}
		environ++;
	}

	return (path_value);
}

/**
 * print_env - Prints all environment variables.
 * @environ: Pointer to the environment variable.
 *
 * Return: void.
 */
void print_env(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
 * _which - Searches for the full path of a comnd executable file.
 * @path: Pointer to the PATH variable.
 * @command: Pointer to a string containing the name of the command.
 *
 * Return: A pointer to a string containing the full path of the command.
 */
char *_which(char *path, char *command)
{
	char *path_copy, *dir, *full_path;
	struct stat st;

	if (!path || !command)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	dir = _strtok(path_copy, ":");
	while (dir)
	{
		full_path = _strconcat(dir, "/");
		full_path = _strconcat(full_path, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
