#include "main.h"

/**
 * free_mem_exit - free all the memory allocated and leave
 * @cmd: pointer to command memory of strings.
 * Return: Nothing.
 */

void free_mem_exit(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
	exit(0);
}


/**
 * free_memory - frees all the memory allocated for command
 * @cmd: Pointer to allocated memory
 * Return: nothing.
 */
void free_memory(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
}
