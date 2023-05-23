#include "main.h"

/**
 * main - Shell main loop
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: 0 on success.
 */

int main(int argc, char **argv, char **envp)
{
	char *input = NULL;
	char **command = NULL;
	size_t input_size = 0;
	ssize_t chars_read = 0;
	int cycles = 0;
	(void)argc;

	while (1)
	{
		cycles++;
		displayPrompt();
		signal(SIGINT, handleSIGINT);
		chars_read = getline(&input, &input_size, stdin);
		if (chars_read == -1)
			handleEOF(input);
		else if (*input == '\n')
			free(input);
		else
		{
			input[chars_read - 1] = '\0';
			command = tokenizeInput(input, " \0");
			free(input);
			if (isExitCommand(command[0]))
				exitShell(command);
			else if (isChangeDirectoryCommand(command[0]))
				changeDirectory(command[1]);
			else
				executeCommand(command, argv[0], envp, cycles);
		}
		fflush(stdin);
		input = NULL;
		input_size = 0;
	}
	
	// The code will never reach this point, but added for completeness
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * handleSIGINT - Signal handler for SIGINT (Ctrl+C)
 * @signal: Signal number
 * Return: None
 */
void handleSIGINT(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n(shell) $ ", 14);
}

/**
 * displayPrompt - Displays the shell prompt
 * Return: None
 */
void displayPrompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(shell) $ ", 13);
}

/**
 * exitShell - Exits the shell.
 * @command: Tokenized command arguments
 * Return: None
 */
void exitShell(char **command)
{
	int exitStatus = 0;

	if (command[1] != NULL)
	{
		exitStatus = _atoi(command[1]);
	}

	freeMemory(command);
	exit(exitStatus);
}

