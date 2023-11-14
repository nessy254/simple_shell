#include "shell.h"

/**
 *main - Shell begins
 *Initiates a loop, tracking its iterations
 *Invokes various functions
 *@ac: argument count
 *@av: an array of pointers to characters, representing arguments
 *Return: 0 on success; in case of errors, the program exits within functions
 */

int main(int ac, char **av)
{
	(void) ac;
	int iterations, i;
	char *line;
	char **arguments;
	size_t size;

	signal(SIGINT, _sigign);
	for (iterations = 1; 1; iterations++)
	{
		line = NULL;
		size = 0;
		arguments = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &size, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}

		i = countargs(line);
		arguments = parser(line, i);
		if (custom_strcmp(arguments[0], "exit") == 0 &&
			(custom_strlen(arguments[0]) == custom_strlen("exit")))
		{
			if (_exit(arguments, line) == -1)
				err_mess(av, arguments, iterations);
		}
		else if (arguments != NULL && arguments[0] != NULL)
		{
			if (interpreter(arguments) == -1)
				err_mess(av, arguments, iterations);
		}

		free(line);
		free(arguments);
	}

	return (0);
}
