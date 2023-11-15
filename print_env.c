#include "shell.h"

/**
 *print_env - prints environment
 *Return: 0 on success
 */
int print_env(void)
{
	int count;

	for (count = 0; environ[count] != NULL; count++)
	{
		write(STDOUT_FILENO, environ[count], custom_strlen(environ[count]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}

/**
 *find_path - Locates the PATH variable within the environment.
 *@target_name: The name to search for - "PATH".
 *
 *Return: A string containing the complete PATH variable.
 */
char *find_path(char *target_name)
{
	int count = 0;

	/*Iterate through the environment variables until the target is found */
	while (environ[count] != NULL)
	{
		/*Check if the current environment variable matches the target name */
		if (custom_strcmp(environ[count], target_name) == 0)
			break;
		/*If last env variable and no match found, report an error */
		else if (environ[count + 1] == NULL)
			perror("find path");

		count++;
	}

	return (environ[count]);
}
