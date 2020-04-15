#include "holberton.h"

int count_args(char *args)
{
	int i, j;
	int count = 1, mode = 0;
	char *delim = " :";

	if (args == NULL)
	{
		return (count);
	}

	for (i = 0; args[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (args[i] == delim[j] && mode == 0)
			{
				count++;
				mode = 1;
				break;
			}
		}
		if (delim[j] == '\0')
		{
			mode = 0;
		}
	}
	count++;
	return (count);
}
