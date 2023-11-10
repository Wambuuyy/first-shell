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
	return (len);
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

	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0'; /*Append null character at the end */
	return (start);
}

/**
 * strcmp_ - Compares two strings.
 * @string1: The first input string.
 * @string2: The second input string.
 *
 * Return: 0 if the strings are equal, a negative value if s1 is less than s2,
 *         and a positive value if s1 is greater than s2.
 */
int strcmp_(const char *string1, const char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
		{
			return (*string1 - *string2);
		}
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}

/**
 * strcat_ - function that concatenates two strings
 * @string1 - pointer to the destination string
 * @string2 - pointer to the second string the source
 * Return: a pointer to the resulting string or null on failure
 */
char *strcat_(char *string1, char *string2)
{
	char *dest = string1, *result;
	size_t i = 0, str1_len = 0, str2_len = 0;

	while (*string1 != '\0')
	{
		string1++;
		str1_len++;
	}
	while (string2[str2_len] != '\0')
	{
		str2_len++;
	}
	result = malloc(str1_len + str2_len + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	while (i < str1_len)
	{
		result[i] = dest[i];
		i++;
	}
	while (i < str1_len + str2_len)
	{
		result[i] = string2[i - str1_len];
		i++;
	}
	result[str1_len + str2_len] = '\0';
	return (result);
}
