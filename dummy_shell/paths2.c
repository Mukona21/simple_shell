#include "main.h"

/**
 * get_env_var - gets the value of an environment variable
 * @name: name of the environment variable
 * Return: string value of the variable, or NULL if not found
 */
char *get_env_var(const char *name)
{
	int i, j;
	char *value;

	if (!name)

		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}

			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (NULL);
}

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: pointer to pointer to the head of the list
 * @str: string value to be stored in the new node
 * Return: address of the new node
 */
list_path *add_node_end(list_path **head, char *str)
{
	list_path *new, *tmp;

	new = malloc(sizeof(list_path));
	if (!new || !str)
		return (NULL);
	new->dir = str;
	new->t = NULL;

	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->t)
		{
			tmp = tmp->t;
		}
		tmp->t = new;

	}
	return (*head);
}

/**
 * create_path_list - creates a linked list of directories in the PATH variable
 * @path: string value of the PATH variable
 * Return: pointer to the head of the linked list
 */
list_path *create_path_list(char *path)
{
	list_path *head = NULL;
	char *token;
	char *path_copy = _strdup(path);

	token = strtok(path_copy, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (head);
}

/**
 * find_executable - finds the pathname of an executable file
 * @filename: name of the file
 * @path_list: pointer to the head of the linked list of directories in PATH
 * Return: pointer to the pathname of the executable file, or NULL if not found
 */
char *find_executable(char *filename, list_path *path_list)
{
	struct stat st;
	char *pathname;

	list_path *tmp = path_list;

	while (tmp)
	{
		pathname = concat_all(tmp->dir, "/", filename);
		if (stat(pathname, &st) == 0)
			return (pathname);
		free(pathname);
		tmp = tmp->t;
	}
	return (NULL);
}

/**
 * free_list - frees a linked list of type list_path
 * @head: pointer to the head of the linked list
 */
void free_list(list_path *head)
{
	list_path *tmp;

	while (head)
	{
		tmp = head->t;
		free(head->dir);
		free(head);
		head = tmp;
	}
}
