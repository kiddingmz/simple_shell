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
		_puterr("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];
	if (value == NULL)
		value = "";
	if (setenv(name, value, 1) != 0)
	{
		_puterr("setenv");
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
		_puterr("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		_puterr("unsetenv");
	}
	return (0);
}

/**
 * _cd - change the current directory
 *
 * @args: argumetns
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
			_putstring("cd: HOME not set\n");
			return;
		}
	}

	if (chdir(dir) == -1)
		perror("cd");
}

/**
 * exit_status - exit status
 *
 * @args: arguments
 *
 * Return: int
 */

int exit_status(char **args)
{
	int status = 0;

	if (args[1] != NULL)
		status = _atoi(args[1]);
	return (status);
}

/**
 * _check_command - check the command
 *
 * @args: argumetns
 *
 * Return: staus
 */

int _check_command(char **args)
{
	if (!_strcmp(args[0], "exit"))
	{
		return (exit_status(args));
	}
	else if (!_strcmp(args[0], "env"))
	{
		_putenv();
		return (0);
	}
	else if (!_strcmp(args[0], "setenv"))
	{
		_setenv(args);
		return (0);
	}
	else if (!_strcmp(args[0], "unsetenv"))
	{
		_unsetenv(args);
		return (0);
	}
	else if (!_strcmp(args[0], "cd"))
	{
		_cd(args);
		return (0);
	}
	return (1);
}
