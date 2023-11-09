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
		string[len - 1] = '\0';
}

/**
 * free_str - frees the allocated memory for an array of strings
 * @string: pointer to array of strings
 * Return: nothing(its void)
 */

void free_str(char **string)
{
	int i;

	if (string == NULL)
		return;

	for (i = 0; string[i] != NULL; i++)
		free(string[i]);
	free(string);
}
