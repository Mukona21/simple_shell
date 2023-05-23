#include "main.h"

/**
 * createChildProcess - Creates a child process to execute a command.
 *
 * @command: Pointer to the tokenized command.
 * @shellName: Name of the shell.
 * @environment: Pointer to the environmental variables.
 * @cycles: Number of executed cycles.
 *
 * Return: Nothing.
 */
void createChildProcess(char **command, char *shellName, char **environment, int cycles)
{
	int pid = 0;
	int status = 0;
	int waitResult = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: Failed to create child process");
		freeMemoryAndExit(command);
	}
	else if (pid == 0)
	{
		executeCommand(command, shellName, environment, cycles);
		freeMemory(command);
	}
	else
	{
		waitResult = waitpid(pid, &status, 0);
		if (waitResult < 0)
		{
			freeMemoryAndExit(command);
		}
		freeMemory(command);
	}
}


/**
 * changeDirectory - Changes the current working directory.
 *
 * @path: The new directory path.
 *
 * Return: 0 on success, -1 on failure.
 */
int changeDirectory(const char *path)
{
	char *buffer = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buffer, size);

	if (chdir(path) == -1)
	{
		perror(path);
		return -1;
	}

	return 0;
}