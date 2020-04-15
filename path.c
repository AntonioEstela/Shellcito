#include "holberton.h"

int fpath(char **args)
{
	int i = 0, j = 0;
	char *tmp = NULL, **token = NULL, *cwd = NULL;
	struct stat st;

	cwd = getcwd(NULL, 0);
	for (i = 0; environ[i] != NULL; i++)
		if (_strncmp(environ[i], "PATH=") == 0)
			break;
	tmp = _strdup(environ[i]);
	token = _split(tmp, "=:");
	for (j = 0; token[j] != NULL; j++)
	{
		if (args[0][0] == '/')
			break;
		if (_strcmp(args[0], "./") == 0)
			break;
		chdir(token[j]);
		if (stat(args[0], &st) == 0)
		{
			token[j] = _strcat(token[j], "/");
			args[0] = _strconcat(token[j], args[0]);
			if (args[0] == NULL)
			{
				free(cwd);
				free_doubleptr(token);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd), free(cwd), free(tmp);
	if (token[j] == NULL)
	{
		free_doubleptr(token);
		return (-1);
	}
	free_doubleptr(token);
	return (0);
}
