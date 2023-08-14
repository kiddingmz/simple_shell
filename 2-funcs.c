#include "main.h"

/**
 * check_path - check path
 *
 * @path: string
 *
 * Return: int
 */

int check_path(char *path)
{
	struct stat buffer;

	if (stat(path, &buffer) == 0)
		return (1);
	return (0);
}

/**
 * _free_array - free array
 *
 * @av: array
 *
 * Return: nothing
 */

void _free_array(char **av)
{
	size_t i;

	i = 0;
	while (av[i] != NULL)
		free(av[i++]);
}

/**
 * _putchar - print a char
 *
 * @c: char
 *
 * Return: int
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstring - print string
 *
 * @str: string
 *
 * Return: lenght
 */

int _putstring(const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0' && str != NULL; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * _putenv - print env
 *
 * Return: nothing
 */

void _putenv(void)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
	{
		_putstring(environ[i]);
		_putchar('\n');
	}
}
