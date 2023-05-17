#ifndef MELV_H
#define MELV_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

void print_prompt(void);
void get_line(char *line, size_t n);
void split_line(char *line, char **tokens, const char *delim);
void execute_command(char **tokens);
void execmd(char **argv);
int shell_execute_command(char *lineptr);

#endif
