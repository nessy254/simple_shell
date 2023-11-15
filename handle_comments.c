#include "shell.h"

/**
 *handle_comments - Replaces the first '#' character with '\0' if it's preceded by a space
 *@str: A string to modify
 *
 */
void handle_comments(char *str)
{
	int a;
	for (a = 0; str[a] != '\0'; a++)
	{
		if (str[a] == '#' && (a == 0 || str[a - 1] == ' '))
		{
			str[a] = '\0';
			break;
		}
	}
}
