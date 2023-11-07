#include "shell.h"

/**
 * rem_newline - removes newline character from a string
 * @string: the string being parsed
 * Return: nothing
 */

void rem_newline(char *string)
{
  size_t len = strlen_(string);
  if (len > 0 && string[len - 1] == '\n')
    string[len -1] = '\0';
}


/**
 * strlen_ - calculates the length of the string
 * @string: string whose length is being determined
 * Return: the length of the string
 */
size_t strlen_(const char *string)
{
  size_t len = 0;

  while (string[len] != '\0')
    len++;
  return len
}

/**
 * free_str - frees the allocated memory for an array of strings
 * @string: pointer to array of strings
 * Return: nothing(its void)
 */

void free_str(char **string)
{
  if (string == NULL)
    return;

  for(int i = 0; string[i] != NULL; i++)
    free(string[i]);

  free(string);
}
