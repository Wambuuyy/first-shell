#include "shell.h"

/**
 * execute - Executes a command with arguments.
 * @args: Array of command arguments.
 * @program: Name of the program (shell).
 * @env: Array of environmental variables.
 * @exit_code: Exit code for the program.
 */

void execute(char **args, char *program, char **env, int exit_code)
{
	struct stat st;
	char **path = NULL;
	char *fpath = NULL;
	char *error = ": command not found\n";
	char **cpath;

	if (args == NULL || args[0] == NULL)
	{
		write(STDERR_FILENO, "Error: Empty command\n", strlen_("Empty command\n"));
		exit(exit_code);
	}
	if (strcmp_(args[0], "env") == 0)
	{
		p_env(env);
		exit(exit_code);
	}
	path = get_path(env);
	if (stat(args[0], &st) == 0 || path == NULL)
	{
		cpath = (path == NULL) ? NULL : path;
		while (cpath && *current_path)
		{
			fpath = strcat_(*path, args[0]);
			if (stat(fpath, &st) == 0 && execve(fpath, args, env) >= 0)
			{
				perror(program);
				free(fpath);
				free_str(path);
				exit_free(args);
				exit(exit_code);
			}
			free(fpath);
			++cpath;
		}
	}
	write(STDERR_FILENO, args[0], strlen(args[0]));
	write(STDERR_FILENO, error, strlen(error));
	free_str(path);
	exit_free(args);
	exit(exit_code);
}
/**
 * p_env - Prints environmental variables.
 * @env: Array of environmental variables.
 */
void p_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; ++i)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
