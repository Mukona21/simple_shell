#include "main.h"

/**
 * intlen - Determine the number of digits in an integer
 * @n: the given number
 *
 * Return: the length of the integer
 */
int intlen(int n)
{
	int len = 0;

	if (n == 0)
		return (1);

	while (n != 0)
	{
		len++;
		n /= 10;
	}

	return (len);
}

/**
 * write_history - writes a line to the history file
 * @data: the data structure pointer
 *
 * Return: (Success) 1
 *         (Fail)    -1
 */
int write_history(sh_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "history line";
	ssize_t fd, z;
	size_t len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (-1);

	len = strlen(line_of_history);
	z = write(fd, line_of_history, len);
	close(fd);

	if (z < (ssize_t)len)
		return (-1);

	return (1);
}

/**
 * _itoa - convert unsigned integer to string
 * @num: the given number
 *
 * Return: a dynamically allocated string representation of the number
 */
char *_itoa(unsigned int num)
{
	int len = 0, i = 0;
	char *p;

	if (num == 0)
	{
		p = malloc(2);
		if (p == NULL)
			return (NULL);
		p[0] = '0';
		p[1] = '\0';
		return (p);
	}

	len = intlen(num);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';

	while (num != 0)
	{
		p[--len] = (num % 10) + '0';
		num /= 10;
	}

	return (p);
}

/**
 * _atoi - convert string to integer
 * @s: the given string
 *
 * Return: the converted integer value
 */
int _atoi(char *s)
{
	unsigned int val = 0;
	int sign = 1;

	if (s == NULL)
		return (0);

	if (*s == '-')
	{
		sign = (-1);
		s++;
	}

	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		val = (val * 10) + (*s - '0');
		s++;
	}

	return (sign * val);
}

/**
 * print_error - prints error message
 * @data: the data structure pointer
 *
 * Return: (Success) 0
 */
int print_error(sh_t *data)
{
	char *idp = _itoa(data->index);

	if (idp == NULL)
		return (-1);

	PRINT(data->error_msg);
	PRINT("hsh: ");
	PRINT(idp);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");

	free(idp);
	return (0);
}
