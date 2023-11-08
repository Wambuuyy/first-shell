#include "shell.h"

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
  return len;
}

/**
 * strcpy_ - copies a string to a different string
 * @source: pointer to the string that is being copied
 * @destination: the pointer to where the string will be copied to
 * Return: pointer to the copied string
 */

char *strcpy_(char *destination, const char *source)
{
    char *start = destination;
    size_t i = 0;

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Append null character at the end
    return start;
}
