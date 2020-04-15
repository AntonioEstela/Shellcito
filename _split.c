#include "holberton.h"

char **_split(char *buffer, char *delimiters)
{
	char *token = NULL;
	char **args = malloc(sizeof(char *) * _strlen(buffer) + 1);
	int i = 0;

	if (args == NULL || buffer == NULL)
	{
		return (NULL);
	}

	token = strtok(buffer, delimiters);

	while (token != NULL)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimiters);

		i++;
	}
	args[i] = NULL;
	free(token);
	return (args);
}
