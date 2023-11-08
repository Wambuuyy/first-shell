#include "shell.h"

#include <unistd.h>

void perror_(const char *program, int err_code, char **args)
{
  char *error_message = "!!Error";
  char *colon = ": ";
  char *status = ": not found";
  char * err_code = itoa_(err_code);

  write(STDERR_FILENO, program, strlen_(program)); // Replace 5 with the appropriate length of the program name
  write(STDERR_FILENO, colon, 2);
  write(STDERR_FILENO, error_message, strlen_(error_message)); // Replace 5 with the appropriate length of the error message
  write(STDERR_FILENO, " ", 1);
  write(STDERR_FILENO, err_code, strlen(err_code));
  free(err_code);
  write(STDERR_FILENO, colon, strlen(colon));
  write(STDERR_FILENO, args[0], strlen_(args[0])); // Adjust the index and size as needed for the command list argument
  write(STDERR_FILENO, not_found, strlen(not_found));
  write(STDERR_FILENO, "\n", 1);
}
