#include "holberton.h"

int exit_fun(char **args, char *buffer)
{
	if (args && buffer)
	{
		free_doubleptr(args);
		free(buffer);
		exit(EXIT_SUCCESS); /* acomodar numeros de salida */
	}
	return (0);
}
