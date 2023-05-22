#include "main.h"

/**
 * _builtin - checks if the command is a built-in command
 * @data: pointer to the data structure
 *
 * Return: 1 if the command is built-in, 0 otherwise
 */
int _builtin(const void *data)
{
	blt_t blt[] = {
		{"cd", change_directory},
		{"help", display_help_info},
        {"exit", abort_program}
		{NULL, NULL}
	};
	int i;

	for (i = 0; blt[i].cmd != NULL; i++)
	{
		if (_strcmp(data->args[0], blt[i].cmd) == 0)
			return 1;
	}
	return 0;
}

/**
 * convert_to_short_form - checks if the given filename is in short form
 * @data: pointer to the data structure
 *
 * If the filename is in short form, the full path is constructed using the
 * directories specified in the "PATH" environment variable.
 */
int convert_to_short_form(sh_data_t *data)
{
	char *path = _getenv("PATH");
	char *token, *_path;
	struct stat st;

	_path = _strdup(path);
	token = strtok(_path, ":");
	while (token != NULL)
	{
		size_t cmd_len = strlen(token) + strlen(data->args[0]) + 1;
        data->cmd = (char*)malloc(cmd_len * sizeof(char));
        strcpy(data->cmd, token);
        strcat(data->cmd, data->args[0]);

        if (stat(data->cmd, &st) != 0)
    free(data->cmd);
    data->cmd = NULL;

    while ((token = strtok(NULL. ":")) != NULL)
    
    cmd_len = strlen(token) + strlen(data->args[0]) + 1;
    data->cmd = (char*)malloc(cmd_len * sizeof(char));
    strcpy(data->cmd, token);
    strcat(data->cmd, data->args[0]);

    if (stat(data->cmd, &st) == 0)
        break;

        free(data->cmd);
        data->cmd = NULL;
        }

    free(_path);

    if (token == NULL || data->cmd == NULL)
    data->cmd = _strdup(data->args[0]);
}
    
/**
 * validate_path - checks if the given filename is a path
 * @newPathdata: pointer to the data structure
 *
 * Return: 1 if the filename is a path, 0 otherwise
 */
int validate_path(PathD *newPathdata)
{
	if (str_contains_slash(newPathdata->args[0]))
	{
		newPathdata->cmd = _strdup(newPathdata->args[0]);
		return 1;
	}
	return 0;
}
