#include "main.h"
/**
 * tokenizeString - Split a string into tokens based on a delimiter.
 * @str: The string to be tokenized.
 * @delimiter: The delimiter used to split the string.
 * Return: An array of strings (tokens).
 */
char **tokenizeString(const char *str, const char *delimiter)
{
    if (str == NULL || delimiter == NULL)
        return NULL;

    size_t bufferSize = strlen(str) + 1;
    char **tokens = malloc(bufferSize * sizeof(char *));
    if (tokens == NULL)
    {
        perror("Memory allocation error");
        return NULL;
    }

    char *token = strtok((char *)str, delimiter);
    size_t tokenCount = 0;

    while (token != NULL)
    {
        tokens[tokenCount] = strdup(token);
        if (tokens[tokenCount] == NULL)
        {
            perror("Memory allocation error");
            free(tokens);
            return NULL;
        }

        token = strtok(NULL, delimiter);
        tokenCount++;
    }

    tokens[tokenCount] = NULL;
    return tokens;
}
