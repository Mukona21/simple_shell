#include "main.h"

/**
 * tokenizer - Split and create a full string cmd.
 * @string: Delimiter for strtok.
 * @buffer: Pointer to input string.
 * Return: String with full cmd.
 */
char **tokenizer(char *buffer, const char *string)
{
	char *token = NULL, **tokens = NULL;
	size_t bufferSize = 0;
	int tokencount = 0;

	if (buffer == NULL)
		return (NULL);

	bufferSize = string_len(buffer);
	tokens = malloc((bufferSize + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Buffer allocation error");
		free(buffer);
		free_memory(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, string);
	while (token != NULL)
	{
		tokens[tokencount] = malloc(string_len(token) + 1);
		if (tokens[tokencount] == NULL)
		{
			perror("Buffer allocation error");
			free_memory(tokens);
			return (NULL);
		}
		string_copy(tokens[tokencount], token);
		token = strtok(NULL, string);
		tokencount++;
	}

	tokens[tokencount] = NULL;
	return (tokens);
}
