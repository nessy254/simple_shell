#include "shell.h"

/**
 *separate_args - Function that separates arguments from an input string.
 *@input_str: The input string to be split into arguments.
 *@output_arr: An array that holds the resulting arguments.
 */

void separate_args(char *input_str, char *output_arr[])
{
	int k = 0;

	output_arr[k] = custom_strtok(input_str, " ");
	while (output_arr[k] != NULL)
	{
		k++;
		output_arr[k] = custom_strtok(NULL, " ");
	}

	output_arr[k] = NULL;
}

/**
 *process_command - brief Processes a command string.
 *@cmd: Command string to process.
 *@status: Pointer to status variable.
 */
void process_command(char *cmd, ssize_t *status)
{
	char *args[MAX_ARGS];

	separate_args(cmd, args);

	if (handle_cd(args, status) == -1)
		write(STDERR_FILENO, "cd: An error occurred\n", 23);
}

/**
 *main - Function serving as the entry point for a Unix command line shell.
 *@ac: Number of command-line arguments provided.
 *@av: An array containing strings representing the command-line arguments.
 *Return: 0 upon successful execution, 1 in case of an error.
 */

int main(int ac, __attribute__((unused)) char *av[])
{
	size_t length = 0;
	ssize_t status = 0;
	char *str = NULL;

	if (isatty(STDIN_FILENO) && ac == 1)
	{
		while (1)
		{
			char prompt[] = "my_shell$ ";

			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
			getline(&str, &length, stdin);
			str[custom_strlen(str) - 1] = '\0';
			if (custom_strcmp(str, "exit") == 0)
				break;
			else if (custom_strncmp(str, "exit ", 5) == 0)
			{
				char *str_status = str + 5;
				int code_status = custom_atoi(str_status);

				if (code_status != 0 || custom_strcmp(str_status, "0") == 0)
					exit(code_status);
			}
			else if (custom_strncmp(str, "cd", 2) == 0)
			{
				process_command(str, &status);
			}
			_builtin(str);
		}
	}
	else
	{
		while (getline(&str, &length, stdin) != -1)
		{
			str[custom_strlen(str) - 1] = '\0';
			_builtin(str);
		}
	}
	free(str);
	return (0);
}
