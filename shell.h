#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define BUFFER_SIZE 1024
#define MAX_ARGS 10
#define MAX_PATH 1024

int parseArguments(char *line, char **args);
void executeCommand(char *command);
void exitShell();
void printEnvironment();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void handleExitCommand(char *command);
void handleSetenvCommand(char *command);
void handleUnsetenvCommand(char *command);
extern char **environ;
#endif 
