#include "main.h"

/**
 * _check_command - check the command
 *
 * @args: argumetns
 *
 * Return: int
 */

int _check_command(char **args)
{
	if (!args[0])
		return (0);
	if (!_strcmp(args[0], "exit"))
		exit_status(args);
	else if (!_strcmp(args[0], "env"))
		_env();
	else if (!_strcmp(args[0], "setenv"))
		_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		_unsetenv(args);
	else if (!_strcmp(args[0], "cd"))
		_cd(args);
	else if (!_strcmp(args[0], "clear"))
		_clear(args);
	else
		return (0);
	return (1);
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

	/* If no argument is provided, change to HOME directory */
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
 * _clear - clear screnn of terminal
 *
 * @args: arguments
 *
 * Return: int
 */

int _clear(char **args)
{
	(void)args;
	_putstring("\033[2J\033[H");
	return (1);
}

/**
 * _env - Prints all the environment
 *
 * Return: nothing
 */

int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_putstring(environ[i]);
		_putchar('\n');
	}

	return (0);
}

/**
 * exit_status - exit status
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
	free_array(args);
	free_last_input();
	exit(status);
}
