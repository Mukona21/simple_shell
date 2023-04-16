#include "main.h"
#include "unistd.h"

/**
 * handle_sigint - Handles the SIGINT signal
 * @signal_num: The signal number
 */
void handle_sigint(int signal_num)
{
	(void) signal_num;
	write(STDOUT_FILENO, "\nSIGINT received\n", 17);
}
