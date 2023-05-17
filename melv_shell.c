#include "melv.h"

int main(int ac, char **argv)
{
	size_t el = 0;
	char *prompt = " $ ";
	int no_tkn = 0;
	char *linep = NULL, *linepcopy = NULL;
	ssize_t reads;
	const char *delim = " \n";
	int stat;
	char *tkn;
	int i;

	(void)ac;

/* inf loop for prompt */
	while (1)
	{
		write(1, prompt, strlen(prompt));

		reads = getline(&linep, &el, stdin);
		if (reads == -1)
		{
			if (feof(stdin))
			{
				write(1, "Exit\n", strlen("Exit\n"));
				return (-1);
			}
			else
			{
				perror("getline");
				exit(1);
			}
		}

		linepcopy = malloc(sizeof(char) * reads);
		if (linepcopy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(linepcopy, linep);

		tkn = strtok(linepcopy, delim);

		while (tkn != NULL)
		{
			no_tkn++;
			tkn = strtok(NULL, delim);
		}
		no_tkn++;

		argv = malloc(sizeof(char *) * no_tkn);

		tkn = strtok(linepcopy, delim);

		for (i = 0; tkn != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(tkn));
			strcpy(argv[i], tkn);

			tkn = strtok(NULL, delim);
		}
		argv[i] = NULL;
		stat = system(argv[0]);

		if (stat != 0)
		{
			perror("execmd");
			write(1, "Command not found\n", strlen("Command not found\n"));
		}

		free(linepcopy);
		free(linep);
	}


	return (0);
}
