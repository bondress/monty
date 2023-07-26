#include <ctype.h>
#include "monty.h"

/**
 * is_digit - checks if a string is digit
 * @s: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (isdigit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

/**
 * isnumber - checks if a string is a number
 * @s: provided string
 *
 * Return: 1 if string is a number, else, 0.
 */
int isnumber(char *s)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}
