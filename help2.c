#include "main.h"

/**
 * print_help_info - Displays help information for the built-in help command
 * Return: No return value
 */
void print_help_info(void)
{
	char *help_msg = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help_msg, strlen(help_msg));
	help_msg = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help_msg, strlen(help_msg));
	help_msg = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help_msg, strlen(help_msg));
}

/**
 * print_alias_help - Displays help information for the built-in alias command
 * Return: No return value
 */
void print_alias_help(void)
{
	char *help_msg = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help_msg, strlen(help_msg));
	help_msg = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help_msg, strlen(help_msg));
}

/**
 * print_cd_help - Displays help information for the built-in cd command
 * Return: No return value
 */
void print_cd_help(void)
{
	char *help_msg = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help_msg, strlen(help_msg));
	help_msg = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help_msg, strlen(help_msg));
}

