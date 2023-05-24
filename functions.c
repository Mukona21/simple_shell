#include "main.h"

/**
 * stringToInteger - Converts a string to an integer
 * @string: Pointer to the input string
 * Return: Integer equivalent of the input string
 */
int stringToInteger(char *string)
{
    int sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (int i = 0; string[i] != '\0' && flag != 2; i++)
    {
        if (string[i] == '-')
            sign *= -1;

        if (string[i] >= '0' && string[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (string[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}

/**
 * stringLength - Calculates the length of a string
 * @str: Pointer to the input string
 * Return: Length of the string
 */
unsigned int stringLength(char *str)
{
    int len = 0;

    if (!str)
        return 0;

    while (*str++)
        len++;
    
    return (len);
}


/**
 * stringCopy - Copies a string from source to destination
 * @destination: Pointer to the destination string
 * @source: Pointer to the source string
 * Return: Pointer to the destination string
 */
char *stringCopy(char *destination, char *source)
{
    char *temp = destination;

    while (*source)
        *destination++ = *source++;
    
    *destination = '\0';

    return (temp);
}


/**
 * stringConcatenate - Concatenates two strings
 * @destination: Pointer to the destination string
 * @source: Pointer to the source string
 * Return: Pointer to the resulting string
 */
char *stringConcatenate(char *destination, char *source)
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
 * stringCompare - Compares two strings
 * @str1: Pointer to the first string for comparison
 * @str2: Pointer to the second string for comparison
 * Return: 0 if strings are different, 1 if they are the same
 */
int stringCompare(char *str1, char *str2)
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