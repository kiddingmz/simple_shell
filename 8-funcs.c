#include "main.h"

/**
 * exit_status - copy string
 *
 * @args: arguments
 *
 * Return: nothing
 */

void exit_status(char **args)
{
	int status = 0;

	if (args[1] != NULL)
		status = _atoi(args[1]);
	_free_array(args);
	exit(status);
}

/**
 * _putserr - print string error
 *
 * @str: string
 * @name: name of file
 * @c: comand
 *
 * Return: nothing
 */

void _putserr(const char *str, char *name, char *c)
{
	_putstring(name);
	_putstring(": 1: ");
	_putstring(c);
	_putstring(": ");
	_putstring(str);
}

/**
 * _strncmp - Compare two strings
 *
 * @s1: first str
 * @s2: second str
 * @n: number for comparre
 *
 * Return: int
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1, c2;

	while (n-- > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;

		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break;
	}

	return (0);
}
