#include "shell.h"

/**
 *tokenizer - Splits string to tokens based on a specified set of separators.
 *@line: The input string to be tokenized.
 *@len: The length of the input string.
 *
 *Return: A dynamically allocated array of strings representing the tokens.
 *        NULL is returned in case of failure.
 */
char **tokenizer(char *line, int len)
{
	char **tokens = malloc(sizeof(char *) * len);
	char *token;
	int token_count = 0;
	char *separator = " :'\n''\t'";

	if (line == NULL || tokens == NULL)
		return (NULL);

	token = strtok(line, separator);
	while (token != NULL)
	{
		tokens[token_count] = custom_strdup(token);

		if (tokens[token_count] == NULL)
		{
			free(tokens);
			return (NULL);
		}

		token = strtok(NULL, separator);
		token_count++;
	}

	tokens[token_count] = NULL;

	return (tokens);
}

/**
 *execute_command - Forks a child process and executes a new program within it.
 *
 *@args: Pointer to an array of strings indicating argument values.
 *
 *Return: 0 on success, -1 on failure.
 */
int execute_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("error");
		return (EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (EXIT_SUCCESS);
}

/**
 *interpreter - Interprets args[0] and determines which function to execute.
 *
 *@arguments: Arguments to pass to execution.
 *
 *Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int interpreter(char **arguments)
{
	struct stat search_bin;

	if (find_builtins(arguments) == 0)
	{
		return (EXIT_SUCCESS);
	}

	if (find(arguments) == -1)
	{
		return (EXIT_FAILURE);
	}

	if (stat(arguments[0], &search_bin) == -1)
	{
		return (EXIT_FAILURE);
	}

	if (stat(arguments[0], &search_bin) == 0 && S_ISREG(search_bin.st_mode) == 0)
	{
		return (EXIT_FAILURE);
	}

	if (execute_command(arguments) == -1)
	{
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 *custom_sig_handler - Checks if the signal was SIGINT,
 *then prints a newline and the prompt.
 *@signal: The number of the signal.
 *
 *Return: Nothing (void).
 */
void custom_sig_handler(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
