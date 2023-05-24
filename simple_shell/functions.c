#include "main.h"

/**
 * string_length - Calculates the length of a string
 * @str: The string
 * Return: Length of the string
 */
unsigned int string_length(char *str)
{
	int length = 0;

	if (!str)
		return 0;

	while (*str++)
		length++;
	return (length);
}


/**
 * string_compare - Compares two strings
 * @str1: First string for comparison
 * @str2: Second string for comparison
 * Return: 0 if the strings are different, 1 if they are the same
 */

int string_compare(char *str1, char *str2)
{
	unsigned int index = 0;

	while (str1[index])
	{
		if (str1[index] != str2[index])
			return 0;
		index++;
	}

	return (1);
}

/**
 * string_copy - Copies a string to another string
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the destination string
 */

char *string_copy(char *dest, char *src)
{
	char *temp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return temp;
}

/**
 * string_to_integer - Converts a string to an integer.
 * @str: The input string.
 * Return: The integer equivalent.
 */
int string_to_integer(char *str)
{
    int sign = 1;
    unsigned int result = 0;

    // Handle sign if present
    if (*str == '-')
    {
        sign = -1;
        str++; // Move past the sign character
    }

    // Convert the string to an integer
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            result = result * 10 + (*str - '0');
            str++;
        }
        else
        {
            // Ignore non-digit characters and stop conversion
            break;
        }
    }

    return (int)(result * sign);
}

/**
 * string_concatenate - Concatenates two strings.
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the resulting string
 */

char *string_concatenate(char *dest, const char *src)
{
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    size_t total_len = dest_len + src_len + 2;
    char *result = malloc(total_len);

    if (result == NULL) {
        // Failed to allocate memory
        return NULL;
    }

    strcpy(result, dest);
    result[dest_len] = '/'; // Add the '/'
    strcpy(result + dest_len + 1, src);

    return (result);
}
