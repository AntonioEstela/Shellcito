#include "holberton.h"

void err(char **argv, char **args, int times)
{
	char *sep = ": ";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, sep, _strlen(sep));
	/* -------------------------------------*/
	itoa_err(times);
	/* -------------------------------------*/
	write(STDERR_FILENO, sep, _strlen(sep));
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, sep, _strlen(sep));
	write(STDERR_FILENO, "not found\n", 10);
	exit(127);
}


void itoa_err(int times)
{
	int x = 1;
	unsigned int n = times;
	char num;

	while ((n / x) > 9)
		x *= 10;

	while (x >= 1)
	{
		num = ((n / x) % 10) + '0';
		write(STDERR_FILENO, &num, 1);
		x /= 10;
	}
}
