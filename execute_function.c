#include "holberton.h"

int execute_function(char **argv, char **args, int times, int *exit_val)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			err(argv, args, times);
		}
	}
	if (pid < 0)
	{
		free_doubleptr(args);
		exit(EXIT_FAILURE);
	}
	if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			*exit_val = WEXITSTATUS(status);
		}
	}
	return (0);
}
