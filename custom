#include "shell.h"
#include <stddef.h>
#include <stdlib.h>

/**
 *custom_strdup - duplicates a string
 *@src: string to duplicate
 *
 *Return: pointer to the duplicated string
 */

char *custom_strdup(const char *src)
{
	char *dest;
	size_t i;
	size_t len = 0;

	while (src[len])
		len++;

	dest = malloc(len + 1);

	if (!dest)
		return (NULL);

	for (i = 0; i < len; i++)
		dest[i] = src[i];

	dest[len] = '\0';

	return (dest);
}

/**
 *custom_strcpy - copies the string
 *@dest: points to the bufffer
 *@src: points the string
 *Return: 0
 */
char *custom_strcpy(char *dest, char *src)
{
	int i;
	char *pontr = dest;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (pontr);
}

/**
 *custom_strchr - Locates the first occurrence of a character in a string.
 *@s: The string to search.
 *@c: The character to find.
 *
 *Return: If the charr is found, a pointer to the first occurrence.
 *       If the character is not found, NULL is returned.
 */

const char *custom_strchr(const char *s, char c)
{
	const char *result = NULL;

	while (*s != '\0')
	{
		if (*s == c)
		{
			result = s;
			break;
		}

		s++;
	}

	return (result);
}

/**
 *custom_strcat - it concatenates two strings
 *@dest: string which we append to
 *@src: the string to add
 *
 *Return: dest
 */

char *custom_strcat(char *dest, const char *src)
{
	int a, b;

	a = 0;
	b = 0;

	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		b++;
		a++;
	}

	dest[a] = '\0';
	return (dest);
}

/**
 *custom_strlen - length of the string
 *@s: the string whose legth is being checked
 *Return: returns length of the string
 */
int custom_strlen(const char *s)
{
	unsigned int str_len = 0;
	int i;

	for (i = 0; s[i] != '\0'; i++)
		str_len += sizeof(char);
	return (str_len);
}
