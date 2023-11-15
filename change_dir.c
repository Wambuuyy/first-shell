#include "shell.h"

/**
 * cd_builtin - checks if a command is a cd builtin
 * @args: The command to check
 * Return: 1 if command is cd, 0 otherwise
 */
int cd_builtin(char *args)
{
	return(strcmp_(args, "cd") == 0);
}

/**
 * change_dir - executes the cd command
 * @args: array of arguments for the cd command
 * Return: 0 Success, 1 on failure (For Old Pwd Always 0 Case No Old PWD)
 */
int change_dir(char **args)
{
	const int SUCCESS = 0;
	const int FAILURE = -1;
	int store = FAILURE;
	char working_dir[PATH_MAX];

	if (args[1] == NULL)
		store = chdir(getenv("HOME"));
	else if (strcmp_(args[1], "-") == 0)
	{
		store = chdir(getenv("OLDPWD"));
	}
	else

		store = chdir(args[1]);

	if (store == FAILURE)
	{
		perror("hsh");
		return (FAILURE);
	}
	else if (store == SUCCESS)
	{
		getcwd(working_dir, sizeof(working_dir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", working_dir, 1);
	}
	return (SUCCESS);
}
