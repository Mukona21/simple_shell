#include "main.h"

/**
 * _strdup - returns a pointer to a new allocated space in memory, which
 * contains a copy of the string given as a para meter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int i, l;
	char *new_str;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new_str = malloc(sizeof(char) * l + 1);
	if (!new_str)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new_str[i] = str[i];
	}
	new_str[l] = str[l];
	return (new_str);
}

/**
 * concat_all - concats 3 strings in a new allocated memory
 * @name: 1st string
 * @sep: 2nd string
 * @value: 3rd string
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _strlen - it gives the length of a str
 * @str: pointer to the string
 * Return: the length of str
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - write the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1 postv.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a string
 * @str: pointer to string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
