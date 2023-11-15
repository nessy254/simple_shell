#include "shell.h"

/**
 *handle_cd - one
 *@input: Array of strings, input user
 *@status: status exit
 *Return: 0 always
 */
ssize_t handle_cd(char **input, ssize_t *status)
{
	if (input[1] == NULL)
	{
		write(STDERR_FILENO, "usage: cd[DIRECTORY]", 21);
		*status = 2;
		return (0);
	}

	return (0);
}
