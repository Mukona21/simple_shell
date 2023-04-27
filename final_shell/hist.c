#include "main.h"

/**
 * add_history_node - Add a new node to the history linked list
 * @head: A pointer to the head of the linked list
 * @str: The string to add to the history
 *
 * Return: 1 on success, -1 on failure
 */
int add_history_node(history_t **head, char *str)
{
	history_t *new_node = malloc(sizeof(history_t));
	history_t *old_head = *head;

		{
			free_history_list(*head);
			return (-1);
		}

	new_node->command = _strdup(str);
	if (!new_node->command)
	{
		free_history_list(*head);
		return (-1);
	}

	new_node->prev = NULL;
	new_node->next = NULL;
	if (!old_head)
	{
		*head = new_node;
	}
	else
	{
		new_node->next = old_head;
		old_head->prev = new_node;
		*head = new_node;
	}
	return (1);
}

/**
 * free_history_list - Free the memory allocated for the history linked list
 * @head: A pointer to the head of the linked list
 */
void free_history_list(history_t *head)
{
	history_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->command);
		free(temp);
	}
}
