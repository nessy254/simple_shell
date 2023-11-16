#include "shell.h"

/**
 * find_path - Determine the complete file path for a given command.
 * @program: The program to locate.
 * @_pathexec: The PATH environment variable containing directories.
 *
 * Return: The file path of the command, or NULL if the command is not found.
 */


char *find_path(const char *program, char *_pathexec)
{
	char *path_env, path_copy[MAX_LEN], *path_token;

	if (custom_strchr(program, '/') != NULL)
	{
		if (access(program, X_OK) == 0)
		{
			return (custom_strdup(program));
		}
		return (NULL);
	}
	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		char error_msg[] = "PATH error! \n";

		write(2, error_msg, sizeof(error_msg) - 1);
		return (NULL);
	}
	custom_strncpy(path_copy, path_env, sizeof(path_copy) - 1);
	path_copy[sizeof(path_copy) - 1] = '\0';
	path_token = custom_strtok(path_copy, ":");
	while (path_token != NULL)
	{
		size_t path_len = custom_strlen(path_token);
		size_t command_len = custom_strlen(program);

		if (path_len + command_len + 2 <= MAX_LEN)
		{
			custom_strcpy(_pathexec, path_token);
			custom_strcat(_pathexec, "/");
			custom_strcat(_pathexec, program);
			if (access(_pathexec, X_OK) == 0)
				return (custom_strdup(_pathexec));
		}
		path_token = custom_strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * _execve - Perform the execution of the specified command with its arguments.
 * @location: The complete path to the command.
 * @args: An array containing the command's arguments.
 */


void _execve(const char *location, char *args[])
{
	pid_t child_pid;
	int current_status;

	child_pid = fork();
	if (child_pid < 0)
		perror("fork");
	else if (child_pid == 0)
	{
		if (execve(location, args, NULL) == -1)
		{
			char error[] = "Error: directory does not exist\n";

			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(child_pid, &current_status, 0);
}

/**
 * _builtin - handles the user command
 * @str: user input
 */

void _builtin(char *str)
{
	char *args[2], **environ_main = environ_capt();
	char *path, *location, _pathexec[MAX_LEN];
	int i;

	if (custom_strcmp(str, "env") == 0)
	{
		for (i = 0; environ_main[i] != NULL; i++)
		{
			size_t len = custom_strlen(environ_main[i]);

			write(STDOUT_FILENO, environ_main[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	separate_args(str, args);

	path = _getenv("PATH");
	if (!path)
	{
		char error_msg[] = "Error: PATH error!\n";

		write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		return;
	}

	location = find_path(args[0], _pathexec);
	if (!location)
	{
		char error_msg[128];

		custom_strcpy(error_msg, "Error: No such command: ");
		custom_strcat(error_msg, args[0]);
		custom_strcat(error_msg, "\n");
		write(STDERR_FILENO, error_msg, custom_strlen(error_msg));
		free_main_env(environ_main);
		return;
	}
	_execve(location, args);
	free_main_env(environ_main);
	free(location);
}
