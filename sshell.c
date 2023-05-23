#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "sshell.h"

void executecmd(char **argv)
{
	pid_t pid = fork();

	if (pid == 0)
	{
	if (execve(argv[0], argv, environ) == -1)
	{
		perror("execve");
		exit(1);
	}
	}
	else if (pid > 0)
	{
		int status;
		wait(&status);
	}
	else
	{
		perror("fork");
		exit(1);
	}
}
