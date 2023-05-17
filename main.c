#include "main.h"

/**
 * main - the main function
 *
 * Return: 0 on success
 */
int main(void)
{
    sh_t data;
    int pl;

    memset((void *)&data, 0, sizeof(data));
    signal(SIGINT, signal_handler);

    while (1)
    {
        initialize_command(&data);

        if (read_line(&data) < 0)
        {
            if (isatty(STDIN_FILENO))
                PRINT("\n");
            break;
        }

        if (split_line(&data) < 0)
        {
            free_command(&data);
            continue;
        }

        pl = parse_line(&data);

        if (pl == 0)
        {
            free_command(&data);
            continue;
        }

        if (pl < 0)
        {
            print_error(&data);
            continue;
        }

        if (process_command(&data) < 0)
        {
            print_error(&data);
            break;
        }

        free_command(&data);
    }

    free_command(&data);
    exit(EXIT_SUCCESS);
}

/**
 * read_line - reads a line from the stnd input
 * @data: a pointer to the struct of data
 *
 * Return: positive number on success, or a negative number on failure
 */
int read_line(sh_t *data)
{
    char *cursor_ptr, *end_ptr, c;
    size_t size = BUFSIZE, read_status, length, new_size;

    data->line = malloc(size * sizeof(char));
    if (data->line == NULL)
        return (FAIL);

    if (isatty(STDIN_FILENO))
        PRINT(PROMPT);

    for (cursor_ptr = data->line, end_ptr = data->line + size;;)
    {
        read_status = read(STDIN_FILENO, &c, 1);
        if (read_status == 0)
            return (FAIL);

        *cursor_ptr++ = c;

        if (c == '\n')
        {
            *cursor_ptr = '\0';
            return (SUCCESS);
        }

        if (cursor_ptr + 2 >= end_ptr)
        {
            new_size = size * 2;
            length = cursor_ptr - data->line;
            char *new_line = realloc(data->line, new_size * sizeof(char));
            if (new_line == NULL)
            {
                free(data->line);
                return (FAIL);
            }

            data->line = new_line;
            size = new_size;
            end_ptr = data->line + size;
            cursor_ptr = data->line + length;
        }
    }
}

#define DELIMITER " \n\t\r\a\v"

/**
 * split_line - splits line into tokens
 * @data: a pointer to the struct of data
 *
 * Return: 0 on success, or a negative number on failure
 */
int split_line(sh_t *data)
{
    char *token;
    size_t size = TOKENSIZE, new_size, i = 0;

    if (_strcmp(data->line, "\n") == 0)
        return (FAIL);

    data->args = malloc(size * sizeof(char *));
    if (data->args == NULL)
        return (FAIL);

    token = strtok(data->line, DELIMITER);
    if (token == NULL)
        return (FAIL);

    while (token)
    {
        data->args[i++] = token;

        if (i + 2 >= size)
        {
            new_size = size * 2;
            char **new_args = realloc(data->args, new_size * sizeof(char *));
                            if (new_args == NULL)
            {
                free(data->args);
                return (FAIL);
            }

            data->args = new_args;
            size = new_size;
        }

        token = strtok(NULL, DELIMITER);
    }

    data->args[i] = NULL;
    return (SUCCESS);
}

#undef DELIMITER
#define DELIMITER ":"

/**
 * parse_line - parses arguments to valid command
 * @data: a pointer to the struct of data
 *
 * Return: 0 on success, or a negative number on failure
 */
int parse_line(sh_t *data)
{
    if (is_path_form(data) > 0)
        return (SUCCESS);

    if (is_builtin(data) > 0)
    {
        if (handle_builtin(data) < 0)
            return (FAIL);
        return (NEUTRAL);
    }

    is_short_form(data);
    return (SUCCESS);
}

#undef DELIMITER

/**
 * process_command - process command and execute process
 * @data: a pointer to the struct of data
 *
 * Return: 0 on success, or a negative number on failure
 */
int process_command(sh_t *data)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        signal(SIGINT, SIG_DFL);
        if (execve(data->cmd, data->args, environ) < 0)
        {
            data->error_msg = _strdup("not found\n");
            return (FAIL);
        }
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
    }

    return (SUCCESS);
}

