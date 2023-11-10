#include "shell.h"

/**
 * display_prompt - A funtion that displays or prints the prompt
 * description: It does not take any parameters
 * Return: it is void; so nothing
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Pru$ ", 5);
}

/**
 * sign_handle - A function that handles the Ctrl + C
 * @signal: the signal to be handled
 * Return: nothing
 */
void sign_handle(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\nPru$ ", 6);
}

/**
 * handle_EOF - handles end-of-file condition and frees the buffer
 * @input_buf: pointer to a pointer to string that is entered(inputted)
 * Return: Nothing
 */
void handle_EOF(char **input_buf)
{
	if (*input_buf)
	{
		free(*input_buf);
		*input_buf = NULL;
	}

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	exit(EXIT_SUCCESS);
}

/**
 * signal_handler - Sets up a signal handler for the SIGINT signal
 * Description: This function sets up a signal handler for the SIGINT signal
 * Return: nothing.
 */
void signal_handler(void)
{
	signal(SIGINT, sign_handle);
}
