#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parse.h"
#include "shell.h"
#define MAX_PATH 1024
#define MAX_ARGS 10

int parseCommand(char *command, char **args);

/**
 * executeCommand - Executes a command in a new process
 * @command: The command to execute
 */

void executeCommand(char *command)
{
	pid_t pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		char *args[MAX_ARGS];
		int i = 0;

		args[i++] = strtok(command, " ");

		while (i < MAX_ARGS - 1)
		{
			args[i] = strtok(NULL, " ");

			if (args[i] == NULL)
				break;
			i++;
		}
		args[i] = NULL;
		execvp(args[0], args);
		perror("execvp");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * exitShell - Exits the shell
 */

void exitShell(void)
{
	const char exitMsg[] = "Exiting the shell...\n";

	write(STDOUT_FILENO, exitMsg, sizeof(exitMsg) - 1);
	exit(0);
}
