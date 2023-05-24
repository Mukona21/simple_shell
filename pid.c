#include "main.h"

/**
  * change_directory -  function that changes working directory
  *
  * @path: The new current working directory
  *
  * Return: 0 on success, -1 on failure.
  */

int change_directory(const char *path)
{
	char *buff = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buff, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (45);
	}
	return (1);
}


/**
 * child_pro - Function that creates a sub process.
 * @cmd: Pointer to tokenize command
 * @name: shell name of pointer.
 * @en: environ variable pointers.
 * @cycles: number of executed cycles.
 * Return: Nothing.
 */
void child_pro(char **cmd, char *name, char **en, int cycles)
{
	int pid = 0;
	int status = 0;
	int waitResult = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_mem_exit(cmd);
	}
	else if (pid == 0)
	{
		execute_cmd(cmd, name, en, cycles);
		free_memory(cmd);
	}
	else
	{
		waitResult = waitpid(pid, &status, 0);
		if (waitResult < 0)
		{
			free_mem_exit(cmd);
		}
		free_memory(cmd);
	}
}
