#include "main.h"

/**
 * _setenv - set env
 *
 * @args: arguments
 *
 * Return: nothing
 */

int _setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];
	if (value == NULL)
		value = "";
	if (setenv(name, value, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - unset env
 *
 * @args: arguments
 *
 * Return: nothing
 */

int _unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		_puterror("unsetenv");
	}
	return (0);
}

/**
 * _putstring - Print the string
 *
 * @str: string
 *
 * Return: nothing
 */

void _putstring(char *str)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(str);
	num_written = write(STDOUT_FILENO, str, len);
	if (num_written == -1)
	{
		perror("write");
	}
}

/**
 * _puterror - print error
 *
 * @err: error message
 *
 * Return: nothing
 */

void _puterror(char *err)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(err);
	num_written = write(STDERR_FILENO, err, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
