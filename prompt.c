#include "shell.h"

/**
 * display_prompt - A funtion that displays or prints the prompt
 * description: It does not take any parameters
 * Return: it is void; so nothing
 */

void display_prompt (void)
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
 * @input: pointer to a pointer to string that is entered(inputted)
 * Return: Nothing
 */
void handle_EOF(char **input)
{
  if (*input) {
        free(*input);
        *input = NULL;
    }

    if (isatty(STDIN_FILENO)) {
        write(STDOUT_FILENO, "\n", 1);
    }
    free(*input);
    exit(EXIT_SUCCESS);
}

void signal_handler()
{
  signal(SIGNINT, sign_handle);
}
