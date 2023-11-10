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

	if (args ==NULL || args[0] == NULL)
	{
		write (STRERR_FILENO, "Error: Empty command\n", strlen_("Empty command\n"));
		exit(exit_code);
	}
	if (strcmp_(args[0], "env") == 0)
	{
		p_env(env);
		exit(exit_code);
	}
	if (stat(args[0], args, env) == 0)
	{
		if (execve(args[0], args, env) < 0)
		{
			perror(program);
			exit_free(args);
			exit(exit_code);
		}
	}
	else
	{
		path = get _path(env);
		for (i = 0; path[i] != NULL; ++i)
		{
			fpath = strcat_(path[i], args[0]);
			if (stat(fpath, &st) == 0)
			{
				if (execve(full_path, args, env) < 0)
				{
					perror(program);
					free(full_path);
					free_dp(pathways);
					exit_free(args);
					exit(err_code);
				}
			}
			free(full_path);
		}
		/* command not found in PATH dir*/
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": command not found\n", strlen(": command not found\n"));
		free_dp(pathways);
		exit_free(args);
		exit(err_code);
	}
}

/**
 *
 *
 *
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

/**
 *
 *
 *
 *
 */


/**
 *  * get_path - Extracts and tokenizes the PATH variable from the environment.
 *   * @env: The array of environmental variables.
 *    *
 *     * Return: An array of paths or NULL if PATH is not found.
 *      */
char **get_path(char **env)
{
	char **path = NULL;
	int i;

	/* Find the PATH variable in the environment */
	for (i = 0; env[i] != NULL; ++i)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			/* Allocate memory for path array */
			char *path_var = env[i] + 5; /* Skip "PATH=" in the environment variable */
			path = (char **)malloc(sizeof(char *));
			if (path == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}

			/* Tokenize the PATH variable using ':' as delimiter */
			char *token = strtok(path_var, ":");
			int count = 0;

			while (token != NULL)
			{
				/* Allocate memory for each path in the array */
				path[count] = strdup(token);
				if (path[count] == NULL)
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}
				++count;

				/* Resize the path array */
				path = (char **)realloc(path, (count + 1) * sizeof(char *));
				if (path == NULL)
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}

				token = strtok(NULL, ":");
			}

			/* Null-terminate the array */
			path[count] = NULL;

			break; /* Exit the loop once PATH is found */
		}
	}
	return path;
}

