#include "shell.h"
/**
 * handleCdCommand - Handles the cd command
 * @command: The command string
 */
void handleCdCommand(char *command)
{
	char *arg = strtok(command, " ");
	char cwd[PATH_MAX];
	arg = strtok(NULL, " ");

	if (arg == NULL)
	{
		arg = getenv("HOME");
		if (arg == NULL)
		{
			perror("cd");
			return;
		}
	}
	else if (strcmp(arg, "-") == 0)
	{
		arg = getenv("OLDPWD");
		if (arg == NULL)
		{
			perror("cd");
			return;
		}
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("cd");
		return;
	}
	if (chdir(arg) == -1)
	{
		perror("cd");
		return;
	}
	if (setenv("OLDPWD", cwd, 1) == -1)
	{
		perror("cd");
		return;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("cd");
		return;
	}
	if (setenv("PWD", cwd, 1) == -1)
	{
		perror("cd");
		return;
	}
}
