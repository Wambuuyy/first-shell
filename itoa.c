#include "shell.h"

/**
 * itoa_ - converts an unsigned integer to a string
 * @num: numbeng converted to a string
 * Return: pointer to the resulting string
 */
char *itoa_(unsigned int num)
{
	int len = 0;
	unsigned int temp;
	char *str;

	if (num == 0)
	{
		str = (char *)malloc(2);
		if (!str)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	temp = num;
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
