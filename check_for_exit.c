#include "holberton.h"

int check_exit(char **args, char *buffer, int exit_value)
{
	free_doubleptr(args);
	free(buffer);
	exit(exit_value);
}
