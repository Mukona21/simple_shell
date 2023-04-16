#include "main.h"

/**
 * print_env_help - Prints help information for the "env" builtin command
 * Return: No return value
 */
void print_env_help(void)
{
	char *help_str = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}

/**
 * print_setenv_help - Prints help information for the "setenv" builtin command
 * Return: No return value
 */
void print_setenv_help(void)
{
	char *help_str = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "int replace)\n\t";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}

/**
 * print_unsetenv_help - Prints help info for the "unsetenv" builtin comd
 * Return: No return value
 */
void print_unsetenv_help(void)
{
	char *help_str = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}

/**
 * print_general_help - Entry point for help infor for the help builtin
 * Return: No return value
 */
void print_general_help(void)
{
	char *help_str = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "comnd are defined internally. Type 'help' to see the list";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "Type 'help name' to find about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = " alias: [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "[dir]\nexit: exit [n]\n  env: env [optn] [n=val] [comnd ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}

/**
 * print_exit_help - Prints help info for the "exit" builtin command
 * Return: No return value
 */
void print_exit_help(void)
{
	char *help_str = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "Exits the shell with a status of N. If N is omitted, the exit";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
	help_str = "status is that of the last command executed.\n";
	write(STDOUT_FILENO, help_str, _strlen(help_str));
}
