#include "main.h"

void __cd(char *dir);

/**
 * __cd - cd
 *
 * @dir: dir
 *
 * Return: nothing
 */

void __cd(char *dir)
{
	char *prev_dir = NULL;

	if (dir != NULL)
	{
		char current_dir[4096];

		if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		{
			perror("cd");
			return;
		}

		prev_dir = _strdup(current_dir);
		if (prev_dir == NULL)
		{
			perror("cd");
			return;
		}

		if (setenv("OLDPWD", prev_dir, 1) == -1)
		{
			perror("cd");
			free(prev_dir);
			return;
		}

		if (chdir(dir) == -1)
		{
			perror("cd");
			free(prev_dir);
			return;
		}
		free(prev_dir);
	}
}

/**
 * __getenv - getenv
 *
 * @name: name
 *
 * Return: string
 */

char *__getenv(const char *name)
{
	size_t namelen = _strlen(name);
	char **env = environ;

	for (; *env != NULL; env++)
	{
		if (_strncmp(*env, name, namelen) == 0 && (*env)[namelen] == '=')
			return (&(*env)[namelen + 1]);
	}

	return (NULL);
}

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

	if (dir == NULL || !_strcmp(dir, ""))
	{
		dir = __getenv("HOME");
		if (dir == NULL)
		_putstring("cd: HOME not set\n");
	}
	else if (!_strcmp(dir, "-"))
	{
		dir = __getenv("OLDPWD");
		if (dir == NULL)
			_putstring("cd: OLDPWD not set\n");
		return;
	}
	_putstring(dir);
	_putstring("\n");
	__cd(dir);
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
	char *value;

	if (args[1] == NULL)
	{
		_putstring("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	value = args[2];
	if (value == NULL)
		value = "";

	if (setenv(args[1], value, 1) != 0)
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
