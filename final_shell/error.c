#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ERROR_CODE 999

/**
 * error_handler - prints an error message to standard error
 * @program_name: the name of the program that encountered the error
 * @error_code: the error code to be printed
 *
 * This function takes in the name of the program that encountered the error
 * and an error code, and prints a corresponding error message to standard
 * error. If the error code is not recognized, a default "unknown error"
 * message is printed instead.
 */
void error_handler(char *program_name, int error_code)
{
	int i = 0, printed = 0;
	size_t program_name_len = strlen(program_name);

	error_msg_t errors[] = {
		{0, "unknown error", 14},
		{100, "error reading from prompt - zero tokens", 40},
		{101, "no such file or directory", 26},
		{102, "fatal error: unable to create child process", 44},
		{103, "command not found", 17},
		{104, "fatal error: no memory available", 33},
		{105, "fatal error: unable to create command list", 38},
		{MAX_ERROR_CODE, "", 0}
	};

	write(STDERR_FILENO, program_name, program_name_len);
	write(STDERR_FILENO, ": ", 2);
	while (errors[i].code != MAX_ERROR_CODE)
	{
		if (errors[i].code == error_code)
		{
			write(STDERR_FILENO, errors[i].msg, errors[i].size);
			write(STDERR_FILENO, "\n", 1);
			printed = 1;
			break;
		}
		i++;
	}
	if (!printed)
	{
		write(STDERR_FILENO, errors[0].msg, errors[0].size);
		write(STDERR_FILENO, "\n", 1);
	}
}
