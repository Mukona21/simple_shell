#include "main.h"

/**
 * strcat_cd_error - function that show the error message for the cd command
 *
 * @data: shell data (includes the directory)
 * @msg: message to print
 * @error_msg: output message
 * @counter_str: string representation of the current command counter
 * Return: error message
 */
char *strcat_cd_error(shell_data *data, char *msg, char *error_msg, char *counter_str)
{
	char *illegal_flag_str;

	_strcpy(error_msg, data->command_name);
	_strcat(error_msg, ": ");
	_strcat(error_msg, counter_str);
	_strcat(error_msg, ": ");
	_strcat(error_msg, data->command_args[0]);
	_strcat(error_msg, msg);

	if (data->command_args[1][0] == '-')
	{
		illegal_flag_str = malloc(3);
		illegal_flag_str[0] = '-';
		illegal_flag_str[1] = data->command_args[1][1];
		illegal_flag_str[2] = '\0';
		_strcat(error_msg, illegal_flag_str);
		free(illegal_flag_str);
	}
	else
	{
		_strcat(error_msg, data->command_args[1]);
	}

	_strcat(error_msg, "\n");
	_strcat(error_msg, "\0");

	return (error_msg);
}

/**
 * get_cd_error - error message for cd command in get_cd function
 * @data: shell data (includes the directory)
 * Return: Error message
 */
char *get_cd_error(shell_data *data)
{
	int length, len_id;
	char *error_msg, *counter_str, *msg;

	counter_str = int_to_string(data->command_counter);

	if (data->command_args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(data->command_args[1]);
	}

	length = _strlen(data->command_name) + _strlen(data->command_args[0]);
	length += _strlen(counter_str) + _strlen(msg) + len_id + 5;
	error_msg = malloc(sizeof(char) * (length + 1));

	if (error_msg == 0)
	{
		free(counter_str);
		return (NULL);
	}

	error_msg = strcat_cd_error(data, msg, error_msg, counter_str);

	free(counter_str);

	return (error_msg);
}

/**
 * not_found_error - generic error message for command not found
 * @data: shell data (includes the command counter and arguments)
 * Return: Error message
 */
char *not_found_error(shell_data *data)
{
	int length;
	char *error_msg;
	char *counter_str;

	counter_str = int_to_string(data->command_counter);
	length = _strlen(data->command_name) + _strlen(counter_str);
	length += _strlen(data->command_args[0]) + 16;
	error_msg = malloc(sizeof(char) * (length + 1));

	if (error_msg == 0)
	{
		free(error_msg);
		free(counter_str);
		return (NULL);
	}

	_strcpy(error_msg, data->command_name);
	_strcat(error_msg, ": ");
	_strcat(error_msg, counter_str);
	_strcat(error_msg, ": ");
	_strcat(error_msg, data->command_args[0]);
	_strcat(error_msg, ": not found\n");
	_strcat(error_msg, "\0");

	free(counter_str);

	return (error_msg);
}

/**
 * exit_shell_error - generic error message for exit
