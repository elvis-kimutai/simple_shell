#include "shell.h"
/**
 * handleCdCommand - Handles the cd command
 * @command: The command string
 */
void handleCdCommand(char *command)
{
	char *arg = command + 3;
	char *home = getenv("HOME");
	char *previousDir = getenv("OLDPWD");
	char cwd[PATH_MAX];
	char *oldPwd = getenv("PWD");

	if (*arg == '\0')
	{
		if (home != NULL)
		{
			if (chdir(home) == -1)
			{
				perror("chdir");
			}
		}
		else
		{
			write(STDERR_FILENO, "Error: HOME environment variable not set\n", strlen("Error: HOME environment variable not set\n"));
		}
	}
	else if (strcmp(arg, "-") == 0)
	{
		if (previousDir != NULL)
		{
			if (chdir(previousDir) == -1)
			{
				perror("chdir");
			}
		}
		else
		{
			write(STDERR_FILENO, "Error: OLDPWD environment variable not set\n", strlen("Error: OLDPWD environment variable not set\n"));
		}
	}
	else
	{
		if (chdir(arg) == -1)
		{
			perror("chdir");
		}
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (setenv("PWD", cwd, 1) == -1)
		{
			perror("setenv");
		}
		if (oldPwd != NULL)
		{
			if (setenv("OLDPWD", oldPwd, 1) == -1)
			{
				perror("setenv");
			}
		}
		else
		{
			write(STDERR_FILENO, "Error: PWD environment variable not set\n", strlen("Error: PWD environment variable not set\n"));
		}
	}
	else
	{
		perror("getcwd");
	}
}
