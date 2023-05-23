#include <string.h>
#include "sshell.h"

/**
 * the_strtok - Tokenize a string
 * @str: String to tokenize
 * @delim: Delimiter characters
 *
 * Return: Pointer to the next token
 */
char *the_strtok(char *str, const char *delim)
{
	static char *next_tkn = NULL;
	char *token_start;
	int i, j;

	if (str != NULL)
	{
		next_tkn = str;
	}

	if (next_tkn == NULL || *next_tkn == '\0')
	{
		return NULL;
	}

	token_start = next_tkn;

	i = 0;
	while (next_tkn[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (next_tkn[i] == delim[j])
			{
				next_tkn[i] = '\0';
				next_tkn = &(next_tkn[i + 1]);
				return (token_start);
			}
			j++;
		}
		i++;
	}

	next_tkn = NULL;
	return (token_start);
}
