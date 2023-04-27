#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: comparison string 1
 * @s2: string 2 for comparison
 * Return: if same, 0 if not
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int inte = 0;

	while (s1[inte])
	{
		if (s1[inte] != s2[inte])
			return (0);
		inte++;
	}

	return (1);
}


/**
 * _strlen - Finds the length of a string
 * @s: string pointer
 * Return: length of the string
 */
unsigned int _strlen(char *s)
{
	int lenght = 0;

	if (!s)
		return (0);

	while (*s++)
		lenght++;
	return (lenght);
}


/**
 * _strcpy - copies a string to another string
 * @dest: pointer to copied string destination
 * @src: pointer to string copied from
 * Return: Pointer to copied string
 */

char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}


/**
 * _strcat - Function that concatenates two strings.
 * @dest: destination for concatenation
 * @src: an input string
 * Return: pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}


/**
 * _atoi - Function that converts string to integer.
 * @str: Input string.
 * Return: integer equivalent.
 */
int _atoi(char *str)
{
	int st;
	int sign = 1, str_f = 0, output;
	unsigned int result = 0;

	for (st = 0;  str[st] != '\0' && str_f != 2; st++)
	{
		if (str[st] == '-')
			sign *= -1;

		if (str[st] >= '0' && str[st] <= '9')
		{
			str_f = 1;
			result *= 10;
			result += (str[st] - '0');
		}
		else if (str_f == 1)
			str_f = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
