#include "shell.h"

/**
 * my_getline - Reads a line from the specified stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: The input stream to read from
 * Return: The number of characters read, or -1 on failure
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;
	static ssize_t bytes_read = 0;
	ssize_t chars_read = 0;
	int newline_found = 0;
	char *new_lineptr;

	if (*n == 0 || *lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
	if ((ssize_t)buffer_index >= bytes_read)
		{
			bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read == 0)
			{
				break;
			}
			else if (bytes_read == -1)
			{
				return (-1);
			}
		}

		(*lineptr)[chars_read] = buffer[buffer_index];
		chars_read++;
		buffer_index++;

		if (buffer[buffer_index - 1] == '\n')
		{
			newline_found = 1;
			break;
		}

		if ((ssize_t)chars_read >= (ssize_t)(*n - 1))
		{
			*n += BUFFER_SIZE;
			new_lineptr = (char *)realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_lineptr;
		}
	}

	(*lineptr)[chars_read] = '\0';

	if (newline_found)
	{
		return (chars_read);
	}
	else
	{
		return (-1);
	}
}
