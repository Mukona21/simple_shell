#include "main.h"

#define SET_OLDPWD(V) (V = _strdup(_getenv("OLDPWD")))

/**
 * change_directory - changes the current directory
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number is returned
 */
int change_directory(sh_t *data)
{
	char *home;

	home = _getenv("HOME");
	if (data->args[1] == NULL)
	{
		SET_OLDPWD(data->oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == NULL)
		{
			SET_OLDPWD(data->oldpwd);
			if (chdir(home) < 0)
				return (FAIL);
		}
		else
		{
			SET_OLDPWD(data->oldpwd);
			if (chdir(data->oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SET_OLDPWD(data->oldpwd);
		if (chdir(data->args[1]) < 0)
			return (FAIL);
	}
	return (SUCCESS);
}

#undef SET_OLDPWD

/**
 * abort_program - exits the program
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number is returned
 */
int abort_program(sh_t *data __attribute__((unused)))
{
	int code;

	if (data->args[1] == NULL)
	{
		free_data(data);
		exit(errno);
	}

	if (!_isdigit(data->args[1]))
	{
		data->error_msg = _strdup("Ill number\n");
		return (FAIL);
	}

	code = _atoi(data->args[1]);
	free_data(data);
	exit(code);
}

/**
 * handle_builtin - handles and manages the built-in commands
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number is returned
 */
int handle_builtin(sh_t *data)
{
	blt_t builtins[] = {
		{"exit", abort_program},
		{"cd", change_directory},
		{"help", display_help},
		{NULL, NULL}
	};
		int i = 0;

	while (builtins[i].cmd != NULL)
	{
		if (_strcmp(data->args[0], builtins[i].cmd) == 0)
			return (builtins[i].f(data));
		i++;
	}

	return (FAIL);
}

/**
 * display_help - displays the help menu
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number is returned
 */
int display_help(sh_t *data)
{
	int ph, rm = 1;
	char t;

	ph = open(data->args[1], O_RDONLY);
	if (ph < 0)
	{
		data->error_msg = _strdup("No help matches the topic\n");
		return (FAIL);
	}

	while (rm > 0)
	{
		rm = read(ph, &t, 1);
		if (rm < 0)
		{
			data->error_msg = _strdup("Cant read the file\n");
			close(ph);
			return (FAIL);
		}
		if (write(STDOUT_FILENO, &t, rm) < 0)
		{
			data->error_msg = _strdup("Cant write: permission denied\n");
			close(ph);
			return (FAIL);
		}
	}

	PRINT("\n");
	close(ph);
	return (SUCCESS);
}
