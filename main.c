#include "main.h"

/**
 * main - shell kernel
 * @num_of_inp_args: Number of inputed args.
 * @arr_of_inp_args: Pointer to array of inputed args.
 * @env: Pointer to array of env variables.
 * Return: 0.
 */

int main(int num_of_inp_args, char **arr_of_inp_args, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cicles = 0;
	(void)num_of_inp_args;

	while (1)
	{
		cicles++;
		prompt();
		signal(SIGINT, handle);
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokening(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				create_child(command, arr_of_inp_args[0], env, cicles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * handle - Handle Ctr + C signal.
 * @_prompt: prompt to handle.
 * Return: Nothing.
 */

void handle(int _prompt)
{
	(void)_prompt;
	write(STDOUT_FILENO, "\n(NMshell) $ ", 14);
}


/**
 * prompt - Prints the prompt
 * Return: Nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(NMshell) $ ", 13);
}


/**
 * shell_exit - Exits the shell.
 * @command: Pointer to tokenized command.
 * Return: nothing
 */
void shell_exit(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		free_mem(command);
		exit(EXIT_SUCCESS);
	}

	status = _atoi(command[1]);
	free_mem(command);
	exit(status);
}


/**
 * _EOF - Chaecks if buffer is EOF
 * @buffer_str: Pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer_str)
{
	if (buffer_str)
	{
		free(buffer_str);
		buffer_str = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer_str);
	exit(EXIT_SUCCESS);
}
