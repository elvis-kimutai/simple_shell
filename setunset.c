#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * handleSetenvCommand - Handles the setenv command
 * @command: The command string
 */

void handleSetenvCommand(char *command)
{
	char *arg = command + 6;
	char *variable = arg;
	char *value = arg;
	while (*arg == ' ')
		arg++;
	while (*arg != ' ' && *arg != '\0')
		arg++;
	if (*arg == '\0' || *(arg + 1) == '\0')
	{
		write(STDERR_FILENO, "Error: Invalid setenv command\n", strlen("Error: Invalid setenv command\n"));
		return;
	}
	*arg = '\0';
	arg++;
	while (*arg == ' ')
		arg++;
	while (*arg != '\0')
		arg++;
	arg--;
	while (*arg == ' ')
	{
		*arg = '\0';
		arg--;
	}
	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
	}
}
/**
 * handleUnsetenvCommand - Handles the unsetenv command
 * @command: The command string
 */
void handleUnsetenvCommand(char *command)
{
	char *space = strchr(command, ' ');

	if (space == NULL)
	{
		write(STDERR_FILENO, "Error: Invalid unsetenv command\n", strlen("Error: Invalid unsetenv command\n"));
		return;
	}

	space++;

	if (unsetenv(space) == -1)
	{
		write(STDERR_FILENO, "Error: Failed to unset environment variable\n", strlen("Error: Failed to unset environment variable\n"));
		return;
	}
}
