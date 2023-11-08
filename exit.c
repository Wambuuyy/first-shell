#include "shell.h"

/**
 * exit_builtin - checks if a string is the exit built-in command.
 * @string: The command to check if it is exit
 * Return: 1 if the command is the exit built-in command, 0 otherwise.
 */
int exit_builtin(char *string)
{
	(strcmp_(command, "exit") == 0) ? return : return 0;
}

/**
 * exit_shell - A function that exits the shell.
 * @args: The command array.
 * @input_buf: user input being read
 * @program: name of the program
 * @exit_code: code at the exit time
 * Return: nothing
 */
void exit_shell(char **args, char *input_buf, char *program, int exit_code)
{
	int condition = 0, i;

	if (args[1] == NULL)
	{
		free(input_buf);
		free_str(args);
		exit(EXIT_SUCCESS);
	}
	if (err_number == 2)/* the ENOENT code*/
	{
		free(input_buf);
		free_str(args);
		pru_exit(2);
	}
	for (i = 0; (args[1][i] != '\0'); i++)
	{
		if (isalpha(args[1][i] != 0)
		{
			perror_(program, err_code, args);
			break;
		}
		else
			{
			condition = atoi(args[1]);
			if (condition < 0)
			{
				free(input_buf);
				free_str(args);
				exit(2)
			}
			else
			{
				free(input_buf);
				free_str(args);
				exit(condition & 0XFF);
			}
		}
	}
}

/*
 * exit_free: enseres the memory is freed before exiting
 * @args: pointer to a pointer to memory to be freed
 *Return: nothing
 */
void exit_free(char **args)
{
	size_t i;

	if (args == NULL)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
	(args[i] == NULL) ? free(args[i]) : free(args);
	exit(EXIT_FAILURE);
}
