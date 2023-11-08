#include "shell.h"

/**
 * is_cd_builtin - checks if a command is a cd builtin
 * @command: The command to check
 * Return: 1 if command is cd, 0 otherwise
 */
int is_cd_builtin(char *command) {
  if (_strcmp(command, "cd") == 0)
    return 1;
  return 0;
}

/**
 * execute_cd_command - executes the cd command
 * @args: An array of arguments for the cd command
 */
void execute_cd_command(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "Expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("Error");
    }
  }
}
