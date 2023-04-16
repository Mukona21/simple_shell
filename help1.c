#include "main.h"

/**
 * display_help - function that retrieves help mes according to the builtin com
 * @shell_data: data structure that contains the arguments and input
 * Return: Return 0
*/
int display_help(shell_data *shell_data)
{

	if (shell_data->args[1] == 0)
		show_general_help();
	else if (_strcmp(shell_data->args[1], "setenv") == 0)
		show_setenv_help();
	else if (_strcmp(shell_data->args[1], "env") == 0)
		show_env_help();
	else if (_strcmp(shell_data->args[1], "unsetenv") == 0)
		show_unsetenv_help();
	else if (_strcmp(shell_data->args[1], "help") == 0)
		show_help_help();
	else if (_strcmp(shell_data->args[1], "exit") == 0)
		show_exit_help();
	else if (_strcmp(shell_data->args[1], "cd") == 0)
		show_cd_help();
	else if (_strcmp(shell_data->args[1], "alias") == 0)
		show_alias_help();
	else
		write(STDERR_FILENO, shell_data->args[0],
		      _strlen(shell_data->args[0]));

	shell_data->status = 0;
	return (1);
}
