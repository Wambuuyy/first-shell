#include "shell.h"

/**
 * child - forks an execution creating a sub-process
 * @args: array of commands
 * @program: name of the program
 * @env: array of the environment variables
 * @iterations: number of cycles
 * Return: nothing
 */
void child(char **args, char *program, char **env, int iterations)
{
	pid_t pid;
	int status = 0, error;

	pid = fork();


	if (pid < 0)
	{
		perror("fork");
		exit_free(args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("execve");
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
