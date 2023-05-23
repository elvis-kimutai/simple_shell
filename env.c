#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * printEnvironment - Prints the environment variables
 */

void printEnvironment(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
