#include "main.h"

/**
 * tokening - Split and create a full string command.
 * @str: Delimiter for strtok.
 * @buffer: Pointer to input string.
 * Return: String with full command.
 */
char **tokening(char *buffer, const char *str)
{
	char *token = NULL, **commands = NULL;
	size_t bufferSize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufferSize = _strlen(buffer);
	commands = malloc((bufferSize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Buffer allocation error");
		free(buffer);
		free_mem(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, str);
	while (token != NULL)
	{
		commands[i] = malloc(_strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Buffer allocation error");
			free_mem(commands);
			return (NULL);
		}
		_strcpy(commands[i], token);
		token = strtok(NULL, str);
		i++;
	}

	commands[i] = NULL;
	return (commands);
}
