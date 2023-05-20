#include "main.h"

/**
 * _isalpha - checks if a character is an alphabetic letter
 * @p: the character to be checked
 *
 * Return: 1 if it is a letter, 0 otherwise
 */

int _isalpha(int p)

{
	if ((p >= 'A' && p <= 'Z') || (p >= 'a' && p <= 'z'))
		return (1);

	return (0);
}

/**
 * _strcpy - copies a string from source to destination
 * @src: the string source
 * @des: the string destination
 *
 * Return: a pointer to destination
 */
char *_strcpy(char *des, const char *src)
{
	char *des_ptr = des;

	if (des == NULL || src == NULL)
		return (NULL);

	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}

	*des = '\0';
	return (des_ptr);
}
