#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void executecmd(char **argv);
extern char **environ;
ssize_t getlne(char **lineptr, size_t *n, FILE *stream);
char *the_strtok(char *str, const char *delim);
char **split_str(char *str, const char *delim, int *num_tokens);

#endif
