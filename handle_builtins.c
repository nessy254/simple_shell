#include "shell.h"

/**
 *_exit - exits the shell
 *@arguments: the arguments passed to _exit
 *arguments[1] will determine the exit status
 *@allocated_line: a dynamically allocated space that should be freed before exit
 *Return: 0 on success, although it will never reach this point
 */
int _exit(char **arguments, char *allocated_line)
{
	int exit_status;

	exit_status = 0;
	if (arguments[1] != NULL)
		exit_status = custom_atoi(arguments[1]);

	if (exit_status == -1)
	{
		return (-1);
	}
	else
	{
		free(allocated_line);
		free(arguments);

		exit(exit_status);
	}
}

/**
 *displayErrorMessage - prints an error message "command not found"
 *
 *@programName: the name of the program
 *Used to print the name of the program
 *
 *@inputArgs: the arguments collected by getline
 *
 *@iterationCount: the number of times the infinite loop has been executed
 *
 *Return: nothing, void
 */
void displayErrorMessage(char **programName, char **inputArgs, int iterationCount)
{
	char *separator = ": ";
	char *errorMessage = "command not found";

	write(STDERR_FILENO, programName[0], custom_strlen(programName[0]));
	write(STDERR_FILENO, separator, custom_strlen(separator));
	err_num(iterationCount);
	write(STDERR_FILENO, separator, custom_strlen(separator));
	write(STDERR_FILENO, inputArgs[0], custom_strlen(inputArgs[0]));
	write(STDERR_FILENO, separator, custom_strlen(separator));
	write(STDERR_FILENO, errorMessage, custom_strlen(errorMessage));
	write(STDERR_FILENO, "\n", 1);
}

/**
 *displayIterationNumber - prints the iteration number
 *
 *@iterations: the number of iterations in the loop
 *
 *Return: void
 */
void displayIterationNumber(int iterations)
{
	int divisor = 1;
	unsigned int number;
	char digit;

	number = iterations;

	while ((number / divisor) > 9)
	{
		divisor *= 10;
	}

	while (divisor >= 1)
	{
		digit = ((number / divisor) % 10) + '0';
		write(STDERR_FILENO, &digit, 1);
		divisor /= 10;
	}
}
