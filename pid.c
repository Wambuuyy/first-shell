#include "shell.h"

/**
 * child - forks an execution creating a sub-process
 * @args: array of commands
 * @env: array of the environment variables
 * Return: nothing
 */
void child(char **args, char *program, char **env, int err_code)
{
	pid_t pid;
	int status = 0, error;

	pid = fork();


	if (pid < 0)
	{
		perror("Fork: ");
		exit_free(args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execute(args, program, env, err_code);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/*parent process*/
		error = waitpid(pid, &status, 0);
		if (error < 0) 
		{
			perror("waitpid");
			exit_free(args);
			exit(EXIT_FAILURE);
		}
	}
}
