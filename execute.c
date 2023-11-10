#include "shell.h"

/**
 *
 *
 *
 */

void execute(char **args, char *program, char **env, int exit_code)
{
	struct stat st;
	char **path = NULL;
	char *fpath = NULL;
	unsigned int i;
	char *error = '": command not found\n";

	if (args == NULL || args[0] == NULL)
		write(STDERR_FILENO, "Error: Empty command\n", strlen_("Empty command\n"));
		exit(exit_code);
	if (strcmp_(args[0], "env") == 0)
		p_env(env);
		exit(exit_code);
	if (stat(args[0], &args, env) == 0)
		if (execve(args[0], &args, env) < 0)
			perror(program);
			exit_free(args);
			exit(exit_code);
	else
		path = get_path(env);
		for (i = 0; path[i] != NULL; ++i)
			fpath = strcat_(path[i], args[0]);
			if (stat(fpath, &st) == 0)
				if (execve(fpath, args, env) < 0)
					perror(program);
					free(fpath);
					free_str(path);
					exit_free(args);
					exit(exit_code);
			free(fpath);
		/* command not found in PATH dir*/
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, &error, strlen(error));
		free_str(path);
		exit_free(args);
		exit(exit_code);
}


void p_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; ++i)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
