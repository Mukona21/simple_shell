#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @string: The given string.
 *
 * Return: On success, returns a pointer to the duplicated string.
 *         On failure, returns NULL.
 */
char *_strdup(char *string)
{
	char *dupl;
	int len, i;

		if (string == NULL)
		return (NULL);

	len = _strlen(string);
	dupl = malloc((len + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dupl[i] = string[i];

	return (dupl);
}

/**
 * _strlen - Calculates the length of a given string.
 * @string: The given string.
 *
 * Return: The length of the string.
 */
int _strlen(char *string)
{
	int length = 0;

	while (string[length])
		length++;

	return (length);
}

/**
 * _strcmp - Compares two strings.
 * @str1: The 1st given string.
 * @str2: The 2nd given string.
 *
 * Return: 0 if the strings are equal,negative if fails
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
		return (1);

	while (str1[i] && str1[i] == str2[i])
		i++;

	return (str1[i] - str2[i]);
}

/**
 * _strchr - Locates a character in a given string.
 * @string: The given string.
 * @q: The character to search for.
 *
 * Return: A pointer to the 1st of q in string, or NULL if not found.
 */
char *_strchr(char *string, char q)
{
	if (string == NULL)
		return (NULL);

	while (*string)
	{
		if (*string == q)
			return (string);
		string++;
	}

	return (NULL);
}

/**
 * _strcat - Concatenates two strings into a path.
 * @frst: The 1st given destination.
 * @sec: The 2nd given source.
 *
 * Return: On success, returns a newly allocated string with the concatenated
 *         path. On failure, returns NULL.
 */
char *_strcat(char *frst, char *sec)
{
	int len1, len2, p = 0, r = 0;
	char *result;

	len1 = _strlen(frst);
	len2 = _strlen(sec);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);

	for (; frst[r]; r++)
		result[p++] = frst[r];
	result[p++] = '/';
	for (r = 0; sec[r]; r++)
		result[p++] = sec[r];
	result[p] = '\0';

	return (result);
}
