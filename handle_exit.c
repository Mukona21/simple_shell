#include "main.h"

/**
 * handle_exit - Entry point
 * @args: array of pointers to strings containing the input arguments
 */

void handle_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}
	free(args[0]);
	free(args);
	exit(status);
}
