#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 1024

/**
 * main - Main function for the pmrm program.
 * Reads user input from stdin, creates a child process to execute the command,
 * and waits for the child process to complete.
 *
 * Return: 0 on success, non-zero on failure.
 */

int main(void)
{
	char *line;
	char *args[2];
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = NULL;
		ssize_t read = getline(&line, &(size_t){0}, stdin);

		if (read == -1)
		{
			break;
		}

		args[0] = line;
		args[1] = NULL;

		pid_t pid = fork();

		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Error");
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
