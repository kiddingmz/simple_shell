#include "main.h"


/**
 * _cd - change current directory
 *
 * @args: array of arguments
 *
 * Return: nothing
 */

void _cd(char **args)
{
	char *dir = args[1];

	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_putstring("cd: No HOME directory found\n");
			return;
		}
	}

	if (chdir(dir) == -1)
		perror("cd");
}

/**
 * _setenv - set env variable
 *
 * @args: arguments
 *
 * Return: int
 */

int _setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		_putstring("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		_putstring("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - unset env variable
 *
 * @args: arguments
 *
 * Return: int
 */

int _unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		_putstring("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
		_putstring("unsetenv");
	return (0);
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

