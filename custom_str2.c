#include "shell.h"

/**
 *custom_atoi - converts a string to an integer
 *@s: string to convert
 *
 *Return: The integer value of the string
 */

int custom_atoi(char *s)
{
	int result = 0;
	int sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return (result * sign);
}

/**
 *custom_strcmp - compares two strings
 *@s1: first string
 *@s2: second string
 *
 *Return: 0 if strings are equal, 1 if s1 > s2, -1 if s1 < s2
 */

int custom_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}

	return ((*s1 > *s2) ? 1 : -1);
}

/**
 *custom_strncmp - compares two strings
 *@s1: first string
 *@s2: second string
 *@n: number of bytes to compare
 *
 *Return: 0 if strings are equal, 1 if s1 > s2, -1 if s1 < s2
 */

int custom_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}

		i++;
	}

	if (i < n)
	{
		if (s1[i])
		{
			return (1);
		}
		else if (s2[i])
		{
			return (-1);
		}
	}

	return (0);
}

/**
 *custom_strncpy - copies a string with a maximum length
 *@dest: destination string
 *@src: source string
 *@n: maximum number of characters to copy
 *
 *Return: Pointer to the destination string
 */

char *custom_strncpy(char *dest, const char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		dest[i] = src[i];

		if (src[i] == '\0')
			break;
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
