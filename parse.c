#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parse.h"
#define MAX_ARGS 10

/**
 * parseArguments - Parses the command line arguments
 * @line: The input line containing the arguments
 * @args: Array to store the parsed arguments
 *
 * Return: The number of arguments parsed
 */

int parseArguments(char *line, char **args)
{
	int count = 0;
	char *token = strtok(line, " \t\n");

	while (token != NULL && count < MAX_ARGS - 1)
	{
		args[count++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[count] = NULL;
	return (count);
}
