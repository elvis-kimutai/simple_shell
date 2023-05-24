#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define UNUSED(x) (void)(x)
/**
 * handleExitCommand - Handles the exit command
 * @command: The exit command with arguments
 */

void handleExitCommand(char *command)
{
	UNUSED(command);
	exitShell(0);
}
