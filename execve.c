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
