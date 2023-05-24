#include "main.h"

/**
 * tokenizeString - Split a string into tokens based on a delimiter.
 * @str: Input string to tokenize.
 * @delimiter: Delimiter used for tokenization.
 * Return: Array of strings representing the tokens.
 */
char **tokenizeString(const char *str, const char *delimiter)
{
	char *token = NULL, **tokens = NULL;
	size_t bufferSize = 0;
	int tokenCount = 0;

	if (str == NULL)
		return (NULL);

	bufferSize = strlen(str);
	tokens = malloc((bufferSize + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	token = strtok((char *)str, delimiter);
	while (token != NULL)
	{
		tokens[tokenCount] = malloc(strlen(token) + 1);
		if (tokens[tokenCount] == NULL)
	{
		perror("Memory allocation error");
		freeTokens(tokens, tokenCount);
		return (NULL);
	}
	strcpy(tokens[tokenCount], token);
	token = strtok(NULL, delimiter);
	tokenCount++;
	}

	tokens[tokenCount] = NULL;
	return (tokens);
}

/**
 * freeTokens - Free memory allocated for an array of strings.
 * @tokens: Array of strings.
 * @count: Number of elements in the array.
 */
void freeTokens(char **tokens, int count)
{
	if (tokens == NULL)
	return;

	for (int i = 0; i < count; i++)
	{
		if (tokens[i] != NULL)
		free(tokens[i]);
	}

	free(tokens);
}
