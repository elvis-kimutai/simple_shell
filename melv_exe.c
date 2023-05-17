#include "melv.h"

void execmd(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
/* get the command */
		cmd = argv[0];

/* execute the command with execve */
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}

}
