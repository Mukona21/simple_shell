#include "main.h"

/**
 * main - Simple Shell
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv, char **envp)
{
	char *input_buffer = NULL, **command_tokens = NULL;
	size_t buffer_size = 0;
	ssize_t chars_read = 0;
	int cycles = 0;
	(void)argc;

	while (1)
	{
		cycles++;
		display_prompt();
		signal(SIGINT, handle_signal);
		chars_read = getline(&input_buffer, &buffer_size, stdin);
		if (chars_read == EOF)
			handle_eof(input_buffer);
		else if (*input_buffer == '\n')
			free(input_buffer);
		else
		{
			input_buffer[chars_read - 1] = '\0';
			command_tokens = tokening(input_buffer, " \0");
			free(input_buffer);
			if (compare_strings(command_tokens[0], "exit") != 0)
				exit_shell(command_tokens);
			else if (compare_strings(command_tokens[0], "cd") != 0)
				change_directory(command_tokens[1]);
			else
				execute_command(command_tokens, argv[0], envp, cycles);
		}
		fflush(stdin);
		input_buffer = NULL, buffer_size = 0;
	}
	if (chars_read == -1)
		return (-1);
	return (0);
}

/**
 * handle_signal - Signal handler for Ctrl+C (SIGINT)
 * @signal: Signal number
 * Return: Nothing
 */
void handle_signal(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n(SimpleShell) $ ", 17);
}

/**
 * display_prompt - Displays the shell prompt
 * Return: Nothing
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(SimpleShell) $ ", 16);
}

/**
 * exit_shell - Exits the shell
 * @command: Array of command tokens
 * Return: Nothing
 */
void exit_shell(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		free_tokens(command);
		exit(0);
	}

	status = atoi(command[1]);
	free_tokens(command);
	exit(status);
}

/**
 * handle_eof - Handles the end-of-file (EOF) condition
 * @input_buffer: Input buffer string
 * Return: Nothing
 */
void handle_eof(char *input_buffer)
{
	if (input_buffer)
	{
		free(input_buffer);
		input_buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(input_buffer);
	exit(0);
}
