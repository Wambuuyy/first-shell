#include "shell.h"

/**
 * tokenizer - splits a string to tokens using delimiter
 * @input_buf: pointer to string being broken to tokens
 * @delimiter: used in tokenizing
 * Return: an array of tokens
 */
char **tokenizer(char *input_buf, const char *delimiter)
{
  char *token = NULL;
  char **tokens = NULL;
  size_t buf_size = BUFFER_SIZE;
  int index = 0;

  if (input_buf == NULL)
    return NULL;

  tokens = (char **)malloc((bufsize + 1) * sizeof(char *));
  if (tokens == NULL)
  {
    perror("no memory was allocated...an error occured");
    exit(EXIT_FAILURE);
  }

  token = strtok(input_buf, delimiter);
  while (token != NULL)
  {
    tokens[index] = (char *)malloc(strlen_(token) + 1);
    if (tokens[index] == NULL)
    {
      perror("no memory was allocated...an error occured");
      free_str(tokens);
      return (NULL);
    }
    strcpy_(tokens[index], token);
    token = strtok(NULL, delimiter);
    index++;
  }
  tokens[index] = NULL;
  return tokens;
}
