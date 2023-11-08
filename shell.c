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
  char ** tokens = NULL;
  ssize_t chars_number = 0;
  int iterations = 0;

  while (1)
  {
      iterations++;
      display_prompt();
      signal_handler();
      chars_number = getline(&input_buf, &BUFFER_SIZE, stdin);
      if (chars_number == -1)/* EOF is rep by -1*/
        handle_EOF(input_buf);
      else if (*input_buf == '\n')
        free(input_buf);
      else
      {
        rem_newline(input_buf);
        tokens = tokenizer(input_buf, " \0");
        free(input_buf);
        if (!exit_builtin(tokens[0]))
          exit_shell(tokens, av[0], env, iterations);
        else if (!is_cd_builtin(tokens[0]))
          execute_cd_command(tokens);
        else
          create_child_process(tokens, av[0], env, iterations);
      }
      clear_stdin_buffer();/*fflush(stdin)*/
      input_buf = NULL;
      BUFFER_SIZE = 0;/* reset to 0/
  }
  if (chars_number == -1)
    return (EXIT_FAILURE);
  return(EXIT_SUCCESS);
}
