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


/**
 * get_path - Extracts and tokenizes the PATH variable from the environment.
 * @env: The array of environmental variables.
 * Return: An array of paths or NULL if PATH is not found.
 */
char **get_path(char **env)
{
	char **path = NULL;
	int i;
	char *path_var;
	char *token; 
	int count;

	/* Find the PATH variable in the environment */
	for (i = 0; env[i] != NULL; ++i)
		if (strncmp(env[i], "PATH=", 5) == 0)
			/* Allocate memory for path array */
			path_var = env[i] + 5; /* Skip "PATH=" in the environment variable */
			path = (char **)malloc(sizeof(char *));
			if (path == NULL)
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			/* Tokenize the PATH variable using ':' as delimiter */
			token = strtok(path_var, ":");
			count = 0;
			while (token != NULL)


				/* Allocate memory for each path in the array */
				path[count] = strdup(token);
				if (path[count] == NULL)
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				++count;
				/* Resize the path array */
				path = (char **)realloc(path, (count + 1) * sizeof(char *));
				if (path == NULL)
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				token = strtok(NULL, ":");
			/* Null-terminate the array */
			path[count] = NULL;
			break; /* Exit the loop once PATH is found */
	return path;
}
