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
	int argStart = strlen("exit");
	int argEnd = strlen(command) - 1;
	char exitStatus[16];
	int status;
	
	while (command[argStart] == ' ')
	{
		argStart++;
	}
	if (command[argStart] == '\0')
	{
		status = 0;
	}
	else
	{
		while (argEnd > argStart && command[argEnd] == ' ')
		{
			argEnd--;
		}
		if (argEnd >= argStart)
		{
			strncpy(exitStatus, &command[argStart], argEnd - argStart + 1);
			exitStatus[argEnd - argStart + 1] = '\0';
			status = atoi(exitStatus);
		}
		else
		{
			write(STDERR_FILENO, "Error: Invalid argument for exit\n", strlen("Error: Invalid argument for exit\n"));
			return;
		}
	}
	 exitShell(status);
}
