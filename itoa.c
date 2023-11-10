#include "shell.h"

/**
 * itoa_ - converts an unsigned integer to a string
 * @num: numbeng converted to a string
 * Return: pointer to the resulting string
 */
char *itoa_(unsigned int num)
{
	int len = 0;
	unsigned int temp = num;
	char *str;

	/*count number's digits*/
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}

	str = (char *)malloc(len + 1);
	if (!str)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

