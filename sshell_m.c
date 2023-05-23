#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "sshell.h"

int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t gets_char;
	const char *delim = " \n";
	int num_tokens = 0;
	char **tokens;

	/* Declaring void variables */
	(void)argv;
	(void)argc;

	/* Create a loop for the shell's prompt */
	while (1) {
		write(STDOUT_FILENO, prompt, strlen(prompt));
		gets_char = getlne(&lineptr, &n, stdin);

		/* Check if the getLine function failed or reached EOF or user used CTRL + D */
		if (gets_char == -1 || feof(stdin))
			break;

		/* Allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * gets_char);
		if (lineptr_copy == NULL) {
			perror("memory allocation error");
			return (-1);
		}

		/* Copy lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);

		/* Split the string into an array of words */
		tokens = split_str(lineptr, delim, &num_tokens);

		/* Check if the command exists */
		executecmd(tokens);

		/* Free up allocated memory */
		free(lineptr_copy);
		free(tokens);
	}

	free(lineptr);

	return (0);
}
