#include "holberton.h"

int main(int argc, char **argv)
{
	char *buffer = NULL, **args = NULL;
	size_t length_buff = 0;
	int r = 1, times;
	int exit_value = 0, *exit_num = &exit_value;

	if (argc > 1)
	{
		args = _split(argv[1], DELIMITERS);
		check_exit(args, buffer, exit_value);
		execute_function(argv, args, 1, exit_num);
		exit(EXIT_SUCCESS);
	}
	for (times = 1; 1; times++)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		if (getline(&buffer, &length_buff, stdin) == -1)
		{
			free(buffer);
			write(STDERR_FILENO, "\n", 1);
			return (0);
		}
		if (*buffer != '\n')
		{
			args = _split(buffer, DELIMITERS);
			if (_strncmp(args[0], "exit") == 0)
				check_exit(args, buffer, exit_value);
			r = print_env(args, buffer);
			if (r == 0)
				continue;
			fpath(args);
			execute_function(argv, args, times, exit_num);
			free_doubleptr(args);
		}
	}
	return (exit_value);
}
