#include "main.h"

/**
 * execute_builtin - checks if the command is a built-in and executes it.
 *
 * @command: The command to check.
 * @env: The environment variables.
 *
 * Return: 1 if command is a built-in, 0 otherwise.
 */

int execute_builtin(char *command, char **env)
{
	int i, result;
	builtin_t builtins[] = {
		{"env", print_env},
		{"exit", exit_shell},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].command != NULL; i++)
	{
		result = _strcmp(command, builtins[i].command);
		if (result == 0)
		{
			builtins[i].func(env);
			return (1);
		}
	}

	return (0);
}

