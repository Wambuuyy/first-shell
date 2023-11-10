#include "shell.h"
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
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			/* Allocate memory for path array */
			path_var = env[i] + 5; /* Skip "PATH=" in the environment variable */
			path = (char **)malloc(sizeof(char *));
			(!path) ? perror("Memory allocation error") : exit(EXIT_FAILURE);
			/* Tokenize the PATH variable using ':' as delimiter */
			token = strtok(path_var, ":");
			count = 0;
			while (token != NULL)
			{
				/* Allocate memory for each path in the array */
				path[count] = strdup(token);
				(!path[count]) ? perror("Memory allocation error") : exit(EXIT_FAILURE);
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
	return (path);
}
