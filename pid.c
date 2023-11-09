#include "shell.h"

/**
 * child - forks an execution creating a sub-process
 * @args: array of commands
 * @env: array of the environment variables
 * Return: nothing
 */
void child(char **args, char **env)
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
		if (execve(args[0], args, env) == -1)
		{
			perror("Execution Failed");
			exit_free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*parent process*/
		while (wait(&status) != pid)
		{
			/*it waits for the childprocess to end*/
			continue;
		}
		error = waitpid(pid, &status, 0);
		(error < 0) ? perror("waitpid") : exit_free(args);
	}
}
