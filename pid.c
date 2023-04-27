#include "main.h"

/**
  * change_dir -  function that changes working directory
  *
  * @path: The new current working directory
  *
  * Return: 0 on success, -1 on failure.
  */

int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}


/**
 * create_child - Function that creates a sub process.
 * @command: Pointer to tokenized command
 * @name: Pointer to shell name.
 * @env: Enviromental variables pointer.
 * @cicles: No of executed cicles.
 * Return: Nothing.
 */
void create_child(char **command, char *name, char **env, int cicles)
{
	int p_i_d = 0;
	int status = 0;
	int waitError = 0;

	p_i_d = fork();
	if (p_i_d < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (p_i_d == 0)
	{
		execute(command, name, env, cicles);
		free_mem(command);
	}
	else
	{
		waitError = waitpid(p_i_d, &status, 0);
		if (waitError < 0)
		{
			free_exit(command);
		}
		free_mem(command);
	}
}
