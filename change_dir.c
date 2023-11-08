#include "shell.h"

/**
 * cd_builtin - checks if a command is a cd builtin
 * @args: The command to check
 * Return: 1 if command is cd, 0 otherwise
 */
int cd_builtin(char *args)
{
	if (strcmp_(args, "cd") == 0)
		return (1);
	return (0);
}

/**
 * change_dir - executes the cd command
 * @args: array of arguments for the cd command
 * Return: 0 Success, 1 on failure (For Old Pwd Always 0 Case No Old PWD)
 */
int change_dir(char **args)
{
	int store = -1;
	char working_dir[PATH_MAX];

	if (args[1] == NULL)
		store = chdir(getenv("HOME"));
	else if (strcmp_(cmd[1], "-") == 0)
	{
		store = chdir(getenv("OLDPWD"));
	}
	else

		store = chdir(args[1]);

	if (store == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (store != -1)
	{
		getcwd(working_dir, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", working_dir, 1);
	}
	return (0);
}
