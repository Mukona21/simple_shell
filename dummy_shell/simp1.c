#include "main.h"

/**
 * exitt - exits the shell with or without a return of status num
 * @arv: array of words of the line
 */
void exitt(char **arv)
{
	int i, status;

	if (arv[1])
	{
		status = _atoi(arv[1]);
		if (status <= -1)
		status = 2;
		freearv(arv);
		exit(status);
	}

	for (i = 0; arv[i]; i++)
		free(arv[i]);

	free(arv);
	exit(0);
}

/**
 * _atoi - converts a string into an int
 * @str: pointer to a the str
 * Return: the int
 */
int _atoi(char *str)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;

	while (!((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}

	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (str[i] - '0'));
		i++;
	}

	return (integer);
}

/**
 * print_env - prints the current envir
 * @args: array of argument
 */
void print_env(char **args __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
	_puts(environ[i]);
	_puts("\n");
	}
}

/**
 * set_env - Initialize a new environment variable, or change an existing one
 * @args: array of entered words
 */
void set_env(char **args)
{
	int i, j, k;

	if (!args[1] || !args[2])
	{
	perror(_getenv("_"));
	return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
	{
		while (args[1][j])
	{
		if (args[1][j] != environ[i][j])
		break;

		j++;
	}

		if (args[1][j] == '\0')
	{
		k = 0;
		while (args[2][k])
		{
			environ[i][j + 1 + k] = args[2][k];
			k++;
		}
			environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}

	if (!environ[i])
	{
		environ[i] = concat_all(args[1], "=", args[2]);
		environ[i + 1] = '\0';
	}
}

/**
 * unset_env - Remove an environ variable
 * @args: array of words
 */
void unset_env(char **args)
{
	int i, j;

	if (!args[1])
	{
		perror(_getenv("_"));
		return;
	}

		for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
	{
		while (args[1][j])
	{
		if (args[1][j] != environ[i][j])
		break;

		j++;
	}

		if (args[1][j] == '\0')
		{
			free(environ[i]);
			environ[i] = environ[i + 1];
			while (environ[i])
			{
				environ[i] = environ[i + 1];
				i++;
			}
			return;
		}
	}
	}
}

