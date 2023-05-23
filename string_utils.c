#include <string.h>
#include <stdlib.h>
#include "sshell.h"

/**
 * split_str - Split a string into tokens
 * @str: String to split
 * @delim: Delimiter characters
 * @num_tokens: Pointer to store the number of tokens
 *
 * Return: Array of tokens
 */
char **split_str(char *str, const char *delim, int *num_tokens)
{
	char *token;
	char **tokens = NULL;
	int i;

	token = strtok(str, delim);
	while (token != NULL)
	{
		 (*num_tokens)++;
		 token = strtok(NULL, delim);
	}
	(*num_tokens)++;

	tokens = malloc(sizeof(char *) * (*num_tokens));

	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		 tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		 strcpy(tokens[i], token);
		 token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
