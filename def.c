#include "shell.h"
#include <string.h> 
void print_prompt() {
  printf("$ ");
}

void remove_newline(char *line) {
  int i = strlen(line) - 1;
  if (line[i] == '\n') {
    line[i] = '\0';
  }
}

void remove_comment(char *line) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '#') {
      break;
    }
    i++;
  }
  line[i] = '\0';
}

char **tokenizer(char *line, char *delim) {
  char **tokens = NULL;
  int count = 0;
  int i = 0;
  int j = 0;
  while (line[i] != '\0') {
    if (line[i] == delim[0]) {
      count++;
    } else if (line[i] == '\n') {
      break;
    }
    i++;
  }
  tokens = malloc(sizeof(char *) * (count + 1));
  for (i = 0; line[i] != '\0'; i++) {
    if (line[i] == delim[0]) {
      tokens[j] = malloc(sizeof(char) * (i - j + 1));
      strncpy(tokens[j], line + j, i - j);
      tokens[j][i - j] = '\0';
      j++;
    } else if (line[i] == '\n') {
      tokens[j] = malloc(sizeof(char) * (i - j + 1));
      strncpy(tokens[j], line + j, i - j);
      tokens[j][i - j] = '\0';
      break;
    }
  }
  tokens[j] = NULL;
  return tokens;
}

int parse_command(char *command) {
  if (strcmp(command, "cd") == 0) {
    return 1;
  } else if (strcmp(command, "exit") == 0) {
    return 2;
  } else {
    return 0;
  }
}

void initializer(char **args, int type_command) {
  if (type_command == 1) {
    chdir(args[1]);
  } else if (type_command == 2) {
    exit(0);
  }
}
