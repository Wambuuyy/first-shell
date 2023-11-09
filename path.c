#include "shell.h"

/**
 * find_command - Find the full path of a command
 * @cmd: The command to find
 * Return: The full path of the command if found, otherwise NULL
 */
char *find_command(char *cmd)
{
	char *env_path = getenv("PATH");
	if (env_path == NULL)
	{
		char *error_message = "Error: PATH variable not found\n";
		write(STDERR_FILENO, error_message, strlen(error_message));
		return NULL;
	}
	
	return find_command_in_path(cmd, env_path);
}
/**
 * find_command_in_path - Find the full path of a command in the PATH variable
 * @command: The command to find
 * @env_path: The PATH environment variable
 * Return: The full path of the command if found, otherwise NULL
 */
char *find_command_in_path(char *command, char *env_path)
{
	char *path_copy, *path_token, *full_path;
	size_t command_len, path_token_len;
	if (command == NULL || env_path == NULL || strlen(command) == 0 || strlen(env_path) == 0)
	{
		return NULL;
	}
	path_copy = strdup(env_path);
	if (path_copy == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	command_len = strlen(command);
	path_token = strtok(path_copy, PATH_DELIMITER);
	while (path_token != NULL)
	{
		path_token_len = strlen(path_token);
		full_path = malloc(path_token_len + command_len + 2); /* +2 for '/' and '\0'*/
		if (full_path == NULL)
		{
			perror("Memory allocation failed");
			free(path_copy);
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", path_token, command);
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		path_token = strtok(NULL, PATH_DELIMITER);
	}
	free(path_copy);
	return NULL;
}
