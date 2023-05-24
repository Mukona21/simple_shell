#include "main.h"

/**
  * changeDirectory - Function that changes the working directory.
  *
  * @path: New current working directory.
  *
  * Return: 0 on success, -1 on failure.
  */

int changeDirectory(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);

	if (chdir(path) == -1)
	{
		perror(path);
		return (-1);
	}

	return (0);
}


/**
 * spawnChildProcess - Function that creates a child process to execute a cmnd.
 * @command: Command to execute.
 * @shellNam: Shell name.
 * @env: Environmental variables.
 * @cycles: Number of cycles executed.
 * Return: Nothing.
 */
void spawnChildProcess(char **command, char *shellNam, char **env, int cycles)
{
	int pid = 0;
	int status = 0;
	int waitResult = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		freeAndExit(command);
	} else if (pid == 0)
	{
		executeCommand(command, shellNam, env, cycles);
		freeMemory(command);
	} else
	{
		waitResult = waitpid(pid, &status, 0);
		if (waitResult < 0)
		{
			freeAndExit(command);
		}
		freeMemory(command);
	}
}
