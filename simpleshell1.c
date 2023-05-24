#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH 1024
#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;
	char *line = NULL;
	size_t size = 0;
	ssize_t lineSize;
	int interactiveMode = isatty(STDIN_FILENO);
	size_t argSize = 0;
	char *arg =  NULL;

	while ((lineSize = my_getline(&line, &size, stdin)) != -1)
	{
		if (interactiveMode)
		{
			char prompt[] = "#cisfun$ ";
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

			lineSize = my_getline(&line, &size, stdin);
		}

		line[lineSize - 1] = '\0';
		command = line;

		if (strcmp(command, "cd") == 0)
		{

			if (my_getline(&arg, &argSize, stdin) != -1) 
			{
				arg[strcspn(arg, "\n")] = '\0';
				if (arg[0] == '\0') 
				{
					chdir("/");
				}
				else
				{
					chdir(arg);
				}
				free(arg);
			}
			continue;
		}
		else if (strcmp(command, "exit") == 0)
		{
			handleExitCommand(command);
		}
		else if (strcmp(command, "env") == 0)
		{
			printEnvironment();
			continue;
		}
		else if (strncmp(command, "setenv", 6) == 0)
		{
			handleSetenvCommand(command);
		}
		else if (strncmp(command, "unsetenv", 8) == 0)
		{
			handleUnsetenvCommand(command);
		}
		else
		{
			executeCommand(command);
		}
	}

	free(line);
	return (0);
}
