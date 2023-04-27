#include "main.h"

/**
 * free_exit - free all the memory allocated and exit
 * @command: pointer to command memory
 * Return: Nothing.
 */

void free_exit(char **command)
{
	size_t inte = 0;

	if (command == NULL)
		return;

	while (command[inte])
	{
		free(command[inte]);
		inte++;
	}

	if (command[inte] == NULL)
		free(command[inte]);
	free(command);
	exit(EXIT_FAILURE);
}


/**
 * free_mem - frees all the memory allocated for command
 * @command: Pointer to allocated memory
 * Return: nothing.
 */
void free_mem(char **command)
{
	size_t inte = 0;

	if (command == NULL)
		return;

	while (command[inte])
	{
		free(command[inte]);
		inte++;
	}

	if (command[inte] == NULL)
		free(command[inte]);
	free(command);
}
