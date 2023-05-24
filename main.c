#include "main.h"

/**
 * main - main shell
 * @in_num_args: Number of inputed args.
 * @in_arry_args: Pointer to array of inputed args.
 * @envp: Pointer to array of env variables.
 * Return: 0.
 */

int main(int in_num_args, char **in_arry_args, char **envp)
{
	char *input_buffer = NULL, **cmd = NULL;
	size_t buffer_size = 0;
	ssize_t chars_readed = 0;
	int cycles = 0;
	(void)in_num_args;

	while (1)
	{
		cycles++;
		signal(SIGINT, handle_signal);
		chars_readed = getline(&input_buffer, &buffer_size, stdin);
		if (chars_readed == -1)
			handle_EOF(input_buffer);
		else if (*input_buffer == '\n')
			free(input_buffer);
		else
		{
			input_buffer[string_len(input_buffer) - 1] = '\0';
			cmd = tokenizer(input_buffer, " \0");
			free(input_buffer);

			if (string_compare(cmd[0], "exit") != 0)
			{
				exit_shell(cmd);
			}
			else if (string_compare(cmd[0], "cd") != 0)
			{
				change_directory(cmd[1]);
			}
			else
				child_pro(cmd, in_arry_args[0], envp, cycles);
		}
		fflush(stdin);
		input_buffer = NULL, buffer_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * handle_signal - Handle Ctr + C signal.
 * @prompt_handle: prompt to handle.
 * Return: Nothing.
 */

void handle_signal(int prompt_handle)
{
	(void)prompt_handle;
	write(STDOUT_FILENO, "\n(Simpleshell) $ ", 17);
}


/**
 * prompt - Prints the prompt.
 * Return: Nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(simpleshell) $ ", 16);
}


/**
 * exit_shell - Exits the shell.
 * @cmd: Pointer to tokenized command.
 * Return: nothing
 */
void exit_shell(char **cmd)
{
	int status = 0;

	if (cmd[1] == NULL)
	{
		free_memory(cmd);
		exit(EXIT_SUCCESS);
	}

	status = str_int(cmd[1]);
	free_memory(cmd);
	exit(status);
}


/**
 * handle_EOF - Checks if buffer is EOF
 * @buffer_string: Pointer to the input string.
 * Return: Nothing
 */
void handle_EOF(char *buffer_string)
{
	if (buffer_string)
	{
		free(buffer_string);
		buffer_string = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer_string);
	exit(EXIT_SUCCESS);
}
