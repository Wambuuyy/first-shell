#include "shell.h"

void perror_(const char *program, int err_code, char **args)
{
	char *error_message = "!!Error";
	char *colon = ": ";
	char *status = ": not found";
	char *code = itoa_(err_code);

	write(STDERR_FILENO, program, strlen_(program));
	write(STDERR_FILENO, colon, 2);
	write(STDERR_FILENO, error_message, strlen_(error_message));
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, code, strlen_(code));
	free(code);
	write(STDERR_FILENO, colon, strlen_(colon));
	write(STDERR_FILENO, args[0], strlen_(args[0]));
	write(STDERR_FILENO, status, strlen_(status));
	write(STDERR_FILENO, "\n", 1);
}
