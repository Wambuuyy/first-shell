#include "shell.h"

void perror_(const char *program, int err_code, char **args)
{
	char *error_message = "!!Error";
	char *colon = ": ";
	char *status = ": not found";
	char *err_code = itoa_(err_code);

	write(STDERR_FILENO, program, strlen_(program));
	write(STDERR_FILENO, colon, 2);
	write(STDERR_FILENO, error_message, strlen_(error_message));
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, err_code, strlen(err_code));
	free(err_code);
	write(STDERR_FILENO, colon, strlen(colon));
	write(STDERR_FILENO, args[0], strlen_(args[0]));
	write(STDERR_FILENO, not_found, strlen(not_found));
	write(STDERR_FILENO, "\n", 1);
}
