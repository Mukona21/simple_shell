#include "main.h"

/**
 * string_compare - Compares 2 strings
 * @str1: comparison 1st string
 * @str2: string 2nd for comparison
 * Return: if same, 0 if not the same
 */

int string_compare(char *str1, char *str2)
{
	unsigned int index = 0;

	while (str1[index])
	{
		if (str1[index] != str2[index])
			return (0);
		index++;
	}

	return (1);
}


/**
 * string_len - Finds the length of a strings
 * @str: string pointer
 * Return: length of the string
 */
unsigned int string_len(char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;
	return (len);
}


/**
 * string_copy - copies a string to another destination
 * @destination: pointer to copied string destination
 * @source: pointer to string copied from
 * Return: Pointer to copied string
 */

char *string_copy(char *destination, char *source)
{
	char *temp = destination;

	while (*source)
		*destination++ = *source++;
	*destination = '\0';
	return (temp);
}


/**
 * string_con - Function that concatenates 2 strings.
 * @destination: destination for the concatenation
 * @source: an input string
 * Return: pointer to the resulting strings
 */

char *string_con(char *destination, char *source)
{
	char *temp = destination;

	while (*destination)
		destination++;

	*destination++ = '/';
	while (*source)
		*destination++ = *source++;
	return (temp);
}


/**
 * str_int - that converts string to integer.
 * @string: Input string.
 * Return: integer equivalent.
 */
int str_int(char *string)
{
	int pr;
	int sign = 1, str_k = 0, output;
	unsigned int result = 0;

	for (pr = 0;  string[pr] != '\0' && str_k != 2; pr++)
	{
		if (string[pr] == '-')
			sign *= -1;

		if (string[pr] >= '0' && string[pr] <= '9')
		{
			str_k = 1;
			result *= 10;
			result += (string[pr] - '0');
		}
		else if (str_k == 1)
			str_k = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
