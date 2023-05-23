#include "main.h"

/**
 * freeMemory - frees all the memory allocated for the command array.
 * @command: Pointer to the command array.
 * Return: None.
 */
void freeMemory(char **command)
{
    if (command == NULL)
        return;

    for (int i = 0; command[i] != NULL; i++)
    {
        free(command[i]);
    }

    free(command);
}

/**
 * cleanUpAndExit - frees all the mem allocated for the cmnd array and exits pr
 * @command: Pointer to the command array.
 * Return: None.
 */
void cleanUpAndExit(char **command)
{
    if (command == NULL)
        return;

    for (int i = 0; command[i] != NULL; i++)
    {
        free(command[i]);
    }

    free(command);
    exit(EXIT_FAILURE);
}
