#include "main.h"

/**
 * sig_handler - handles the SIGINT signal (Ctrl+C)
 * @sig_num: integer signal number
*/
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	_puts("\n#shell$ ");
}
/**
 * handle_EOF - handles End of File (EOF)
 * @len: length of getline function's return value
 * @buff: pointer to input buffer
*/
void handle_EOF(int len, char *buff)
{
	(void)buff;
		if (len == -1)
	{
		if (isatty(STDIN_FILENO))
	{
		_puts("\n");
		free(buff);
	}
		exit(0);
	}
}
/**
 * prompt_shell - prints the shell prompt
*/
void prompt_shell(void)
{
	if (isatty(STDIN_FILENO))
	_puts("#shell$ ");
}
/**
 * main - the shell's main function
 * Return: 0 on success
*/
int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *path_val, *pathname, **args;
	size_t size = 0;
	list_path *head = NULL;
	void (*f)(char **);

		signal(SIGINT, sig_handler);
	while (len != EOF)
	{
	prompt_shell();
	len = getline(&buff, &size, stdin);
	handle_EOF(len, buff);
	args = splitstring(buff, " \n");
	if (!args || !args[0])
	execute(args);
	else
	{
		path_val = _getenv("PATH");
		head = linkpath(path_val);
		pathname = _which(args[0], head);
		f = check_buildin(args);
		if (f)
		{
		free(buff);
		f(args);
		}
		else if (!pathname)
		execute(args);
		else if (pathname)
		{
		free(args[0]);
		args[0] = pathname;
		execute(args);
		}
	}
}
	free_list(head);
	freearv(args);
	free(buff);
	return (0);
}
