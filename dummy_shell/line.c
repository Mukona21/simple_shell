#include "main.h"

/**
 * split_string - splits a string and makes it an array of pointers
 * @str: the string to be splited
 * @delim: the delimiter
 * Return: array of pointers to the words
 */

char **split_string(char *str, const char *delim)
{
	int i, word_num;
	char **array;
	char *token;
	char *copy;

	copy = malloc(_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	word_num = 3;
	while (token)
	{
		token = strtok(NULL, delim);
	array = _realloc(array, (sizeof(char *) * (word_num - 1)),
			(sizeof(char *) * word_num));

		array[i] = _strdup(token);
		i++;
		word_num++;
	}
	free(copy);
	return (array);
}

/**
 * execute - executes a comnd
 * @argv: array of arg
 */

void execute(char **argv)
{

	int child_pid, status;

	if (!argv || !argv[0])
		return;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(_getenv("_"));
	}
	if (child_pid == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _realloc - Reallocates mem block
 * @ptr: prev pointer
 * @old_size: old size of prev pointer
 * @new_size: new size for pointer
 * Return: resized Pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * free_arv - frees the array of pntrs arv
 *@arv: array of pointers
 */

void free_arv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
