#include "shell.h"

/**
 *handle_signal- it keeps track of is interactive bool mode
 *@m: the signal number
 */

void handle_signal(int mode)
{
	(void)mode;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
