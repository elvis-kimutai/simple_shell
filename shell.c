#include "shell.h"

int main() {
  char *line = NULL;
  char **commands = NULL;
  int status = 0;
  size_t line_size = 0;
  size_t i;
  int type_command;

  while (1) {
    print_prompt();

    if (getline(&line, &line_size, stdin) == -1) {
      free(line);
      exit(status);
    }

    remove_newline(line);
    remove_comment(line);
    commands = tokenizer(line, ";");

    for ( i = 0; commands[i] != NULL; i++) {
      char **current_command = tokenizer(commands[i], " ");
      if (current_command[0] == NULL) {
        free(current_command);
        break;
      }
      type_command = parse_command(current_command[0]);

      /* initializer -   */
      initializer(current_command, type_command);
      free(current_command);
    }
    free(commands);
  }

  free(line);

  return (status);
}
