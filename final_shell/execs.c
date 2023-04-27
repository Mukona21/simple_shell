#include "main.h"

/**
 * execute_command - Executes a command in a child process.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 * @env: The environment variables.
 *
 * Return: The exit status of the child process.
 */
int execute_command(char *command, char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			return (128 + WTERMSIG(status));
	}

	return (EXIT_FAILURE);
}
