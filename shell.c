#include "shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: argument count (no of input arg)
 * @argv: argument vector (array of input arg)
 * @env: Array of environment variables
 * Return: 0 on success
 */

int  main(int __attribute__((unused)) argc, char **argv, char **env)
{
  char *input_buf = NULL;
  size_t buf_size = BUFFER_SIZE;
  ssize_t chars_number = 0;
  int iterations = 0;

  while (1)
    {
      iterations++;
      display_prompt();
      signal_handler();
      chars_number = getline(&input_buf, &bufsize, stdin);
      if (chars_number == -1)/* EOF is rep by -1*/
        handle_EOF(input_buf);
      else if (*input_buf == '\n')
        free(input_buf);
      else
      {
        /* Im going to create a function to remove a new line, strlen, a tokenizer,
        
  
}
