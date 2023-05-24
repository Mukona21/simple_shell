#include "main.h"

/**
 * freeMemory - Frees allocated memory.
 * @strings: Pointer to the array of strings.
 * Return: None.
 */
void freeMemory(char **strings)
{
	size_t i = 0;

	if (strings == NULL)
	return;

	while (strings[i])
	{
		free(strings[i]);
		i++;
	}

	if (strings[i] == NULL)
	free(strings[i]);

	free(strings);
}

/**
 * freeMemoryAndExit - Frees allocated memory and exits.
 * @strings: Pointer to the array of strings.
 * Return: None.
 */
void freeMemoryAndExit(char **strings)
{
	size_t i = 0;

	if (strings == NULL)
	return;

	while (strings[i])
	{
		free(strings[i]);
		i++;
	}

	if (strings[i] == NULL)
	free(strings[i]);

	free(strings);
	exit(EXIT_FAILURE);
}
