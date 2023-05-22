#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void print_prompt();
void remove_newline(char *line);
void remove_comment(char *line);
char **tokenizer(char *line, char *delim);
int parse_command(char *command);
void initializer(char **args, int type_command);

#endif
