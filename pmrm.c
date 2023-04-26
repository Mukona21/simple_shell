#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

/**
 * main - Entry point
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t bufsize = 0;
	ssize_t chars_read = 0;
	int status = 0, i = 0;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		chars_read = getline(&line, &bufsize, stdin);

		if (chars_read == -1)
	{
		if (errno == EINTR)
			continue;
			break;
	}

		if (line[chars_read - 1] == '\n')
		line[chars_read - 1] = '\0';

		char *token = strtok(line, " ");

		args = &token;

		i = 0;
		while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
			i++;
	}

		pid = fork();
		if (pid == -1)
	{
		perror("./hsh");
		status = 1;
			break;
	}
		else if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("./hsh");
			_exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, WUNTRACED);
		}
	}

	free(line);
	free(args);
	exit(status);
}
