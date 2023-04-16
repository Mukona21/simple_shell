#include "main.h"
#include "data_shell.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @data: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *data, int eval)
{
	char *error_msg;

	switch (eval)
	{
	case -1:
		error_msg = error_env(data);
		break;
	case 126:
		error_msg = error_path_126(data);
		break;
	case 127:
		error_msg = error_not_found(data);
		break;
	case 2:
		if (_strcmp("exit", data->args[0]) == 0)
			error_msg = error_exit_shell(data);
		else if (_strcmp("cd", data->args[0]) == 0)
			error_msg = error_get_cd(data);
		break;
	}

	if (error_msg)
	{
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		free(error_msg);
	}

	data->status = eval;
	return (eval);
}
