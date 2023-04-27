#include "main.h"

/**
 * new_command_node - Creates a new node for a command struct.
 *
 * @shell_name: The name of the shell.
 *
 * Return: On success, a pointer to the newly created command_t struct.
 * On failure, NULL is returned.
 */
command_t *new_command_node(char *shell_name)
{
		command_t *cmd_node = malloc(sizeof(command_t));

		if (!cmd_node)
	{
		perror("Memory allocation error");
			return (NULL);
	}

	cmd_node->command = NULL;
	cmd_node->args = NULL;
	cmd_node->input_file = NULL;
	cmd_node->output_file = NULL;
	cmd_node->next = NULL;

	return (cmd_node);
}

/**
 * add_token_to_command - Adds a token from the command line to a command node.
 * @shell_name: The name of the shell.
 * @cmd_node: The command node to be updated.
 * @index: The position to add the token.
 * @token: The token to be added.
 *
 * Return: On success, 0.
 * On failure, -1 is returned.
 */
int add_token_to_command(char *shell_name,
		command_t *cmd_node, size_t index, char *token)
{
	char **new_command;

	new_command = realloc(cmd_node->command, (index + 1) * sizeof(char *));
	if (!new_command)
	{
		perror("Memory allocation error");
		return (-1);
	}

		cmd_node->command = new_command;
		cmd_node->command[index] = _strdup(token);

		if (!cmd_node->command[index])
	{
		perror("Memory allocation error");
		return (-1);
	}

	return (0);
}
