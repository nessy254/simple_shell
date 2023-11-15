#include "shell.h"

/**
 * _getenv - Locate the value of a specified environment variable.
 * @name: The name of the environment variable to search for.
 *
 * Return: pointer to the value associated with the variable, or NULL.
 */


char *_getenv(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (custom_strncmp(environ[i], name, custom_strlen(name)) == 0 &&
				environ[i][custom_strlen(name)] == '=')
		{
			return (environ[i] + custom_strlen(name) + 1);
		}
	}

	return (NULL);
}

/**
 * env_print - Print the current environment variables.
 */

void env_print(void)
{
	while (*environ != NULL)
	{
		write(1, *environ, custom_strlen(*environ));
		write(1, "\n", 1);

		environ++;
	}
}

/**
 * environ_capt - Capture and duplicate the original environment.
 *
 * Return: A pointer to a copy of the original environment.
 */

char **environ_capt(void)
{
	char **environ_main = NULL;
	int k = 0, i;

	while (environ[k] != NULL)
		k++;

	environ_main = (char **)malloc((k + 1) * sizeof(char *));
	if (!environ_main)
	{
		perror("memory error");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < k; i++)
	{
		environ_main[i] = custom_strdup(environ[i]);
		if (!environ_main[i])
		{
			perror("str duplicate error");
			exit(EXIT_FAILURE);
		}
	}
	environ_main[k] = NULL;

	return (environ_main);
}

/**
 * free_main_env - Release memory allocated for the environment copy.
 * @env_main: Pointer to the array containing the duplicated environment.
 */

void free_main_env(char **env_main)
{
	int i;

	if (env_main)
	{
		for (i = 0; env_main[i] != NULL; i++)
			free(env_main[i]);
		free(env_main);
	}
}
