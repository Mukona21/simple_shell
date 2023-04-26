#include "main.h"

/**
 * check_buildin - checks if the command is a build-in
 * @arguments: array of arguments
 *
 * Return: pointer to function that takes arguments and returns void
 */
void (*check_buildin(char **arguments))(char **arguments)
{
	int i, j;
	mybuild P[] = {
		{"exit", exitt},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; P[i].name; i++)
	{
		j = 0;
		if (P[i].name[j] == arguments[0][j])
		{
			for (j = 0; arguments[0][j]; j++)
			{
				if (P[i].name[j] != arguments[0][j])
					break;
			}
			if (!arguments[0][j])
				return (P[i].func);
		}
	}
	return (NULL);
}
