#include "holberton.h"

void free_doubleptr(char **args)
{
	int height;

	for (height = 0; args[height] != NULL; height++)
	{}

	if (args != NULL && height != 0)
	{
		for (; height >= 0; height--)
		{
			free(args[height]);
		}
		free(args);
	}
}
