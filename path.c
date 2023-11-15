#include "shell.h"

/**
 * find - Passes arguments to find functions.
 * @arguments: Contains the commands to find.
 *
 * Return: 0 on success, -1 on failure.
 */
int find(char **arguments)
{
	char **cmd = NULL;
	int i;
	char *buffer;

	buffer = custom_strdup(find_path("PATH"));
	if (buffer == NULL)
		return (-1);
	i = countArguments(buffer);
	if (i == -1)
	{
		free(buffer);
		return (-1);
	}

	format_eq_sign(&buffer);
	cmd = tokenizer(buffer, i);
	if (cmd == NULL)
	{
		free(buffer);
		return (-1);
	}

	if (find_command_in_dirs(cmd, arguments) == -1)
	{
		free(buffer);
		return (-1);
	}

	free(buffer);
	return (0);
}

/**
 *find_command_in_dirs - Searches directories until a command is found.
 *@directories: Contains pointers to all the directories in the PATH.
 *@command_to_find: Contains the command to look for.
 *
 *Return: -1 on failure, 0 on success.
 */
int find_command_in_dirs(char **directories, char **command_to_find)
{
	char *current_directory;
	int index;
	struct stat sb;

	current_directory = getcwd(NULL, 0);
	index = 0;

	while (directories[index] != NULL)
	{
		if (command_to_find[0][0] == '/')
			break;
		if (custom_strcmp(command_to_find[0], "./") == 0)
			break;
		chdir(directories[index]);
		if (stat(command_to_find[0], &sb) == 0)
		{
			command_to_find[0] = custom_strcat(directories[index],
					command_to_find[0]);
			if (command_to_find[0] == NULL)
			{
				free(current_directory);
				free(directories);
				return (-1);
			}
			break;
		}
		index++;
	}
	chdir(current_directory);
	free(current_directory);
	if (directories[index] == NULL)
	{
		free(directories);
		return (-1);
	}

	free(directories);
	return (0);
}

/**
 *countArguments - Count the number of arguments in a string,
 *considering spaces and colons as delimiters.
 *
 *@str: A pointer to the input string.
 *
 *Return: The count of arguments in the string.
 */
int countArguments(char *str)
{
	int index, argCount, delimiterFlag, delimIndex;

	char *delimiters = " :";

	delimiterFlag = index = 0;
	argCount = 1;
	if (str == NULL)
		return (argCount);

	while (str[index] != '\0')
	{
		for (delimIndex = 0; delimiters[delimIndex] != '\0'; delimIndex++)
		{
			if (str[index] == delimiters[delimIndex] && delimiterFlag == 0)
			{
				argCount++;
				delimiterFlag = 1;
				break;
			}
		}

		if (delimiters[delimIndex] == '\0')
			delimiterFlag = 0;
		index++;
	}

	return (argCount);
}
