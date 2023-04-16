#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @data: data relevant (directory)
 * @msg: message to print
 * @err_msg: output message
 * @counter_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *data, char *msg, char *err_msg, char *counter_str)
{
	char *illegal_flag;

	_strcpy(err_msg, data->av[0]);
	_strcat(err_msg, ": ");
	_strcat(err_msg, counter_str);
	_strcat(err_msg, ": ");
	_strcat(err_msg, data->args[0]);
	_strcat(err_msg, msg);
	if (data->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(err_msg, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err_msg, data->args[1]);
	}

	_strcat(err_msg, "\n");
	_strcat(err_msg, "\0");
	return (err_msg);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @data: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *data)
{
	int length, len_id;
	char *err_msg, *counter_str, *msg;

	counter_str = aux_itoa(data->counter);
	if (data->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(data->args[1]);
	}

	length = _strlen(data->av[0]) + _strlen(data->args[0]);
	length += _strlen(counter_str) + _strlen(msg) + len_id + 5;
	err_msg = malloc(sizeof(char) * (length + 1));

	if (err_msg == 0)
	{
		free(counter_str);
		return (NULL);
	}

	err_msg = strcat_cd(data, msg, err_msg, counter_str);

	free(counter_str);

	return (err_msg);
}

/**
 * error_not_found - generic error message for command not found
 * @data: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *data)
{
	int length;
	char *err_msg;
	char *counter_str;

	counter_str = aux_itoa(data->counter);
	length = _strlen(data->av[0]) + _strlen(counter_str);
	length += _strlen(data->args[0]) + 16;
	err_msg = malloc(sizeof(char) * (length + 1));
	if (err_msg == 0)
	{
		free(err_msg);
		free(counter_str);
		return (NULL);
	}
	_strcpy(err_msg, data->av[0]);
	_strcat(err_msg, ": ");
	_strcat(err_msg, counter_str);
	_strcat(err_msg, ": ");
	_strcat(err_msg, data->args[0]);
	_strcat(err_msg, ": not found\n");
	_strcat(err_msg, "\0");
	free(counter_str);
	return (err_msg);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @data: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell

