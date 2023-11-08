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

/**
 * strcmp_ - Compares two strings.
 * @string1: The first input string.
 * @string2: The second input string.
 *
 * Return: 0 if the strings are equal, a negative value if s1 is less than s2,
 *         and a positive value if s1 is greater than s2.
 */
int strcmp_(const char *string1, const char *string2) {
    while (*string1 && *string2)
    {
      if(*string1 != *string2)
      {
        return *string1 - *string2;
      }
      string1++;
      string2++;
    }

    return *string1 - *string2;
}

