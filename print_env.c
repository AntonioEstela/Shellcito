#include "holberton.h"

int print_env(char **args, __attribute__((unused)) char *buffer)
{
	int i;

	if (_strcmp(args[0], "env") != 0)
		return (-1);

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
