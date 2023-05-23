#include <stdio.h>
#include <stdlib.h>
#include "sshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * getlne - Read a line from a file stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: Number of characters read
 */
ssize_t getlne(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t gets_char = getline(lineptr, n, stream);

	if (gets_char == -1)
	{
		write(STDOUT_FILENO, "Exit\n", 5);
		exit(-1);
	}

	return (gets_char);
}
