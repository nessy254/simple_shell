#include "shell.h"
#include <stddef.h>

/**
 *custom_strtok - Splits a string into tokens
 *@input: The string to split
 *@delimiters: The delimiter to use
 *
 *Return: A pointer to the array of tokens
 */
char *custom_strtok(char *input, char *delimiters)
{
	static char *str;
	char *token_start;

	if (input != NULL)
		str = input;

	for (; *str != '\0' && custom_strchr(delimiters, *str) != NULL; str++)
		continue;

	if (*str == '\0')
		return (NULL);

	token_start = str;

	for (; *str != '\0' && custom_strchr(delimiters, *str) == NULL; str++)
		continue;

	if (*str != '\0')
		*
		str++ = '\0';

	return (token_start);
}
