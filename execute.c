#include "main.h"


void _exe_sub(char *path, char **av, char *c, char *name, char **env);

/**
 * _exe_sub - execute
 *
 * @path: path
 * @av: array
 * @c: command
 * @name: name file
 * @env: env
 *
 * Return: nothing
 */

void _exe_sub(char *path, char **av, char *c, char *name, char **env)
{
	pid_t pid;

	if (path != NULL)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
		{
			if (!_strcmp(c, "env"))
				_putenv(env);
			else
			{
				if (execve(path, av, environ) == -1)
					perror(name);
			}
		}
		else
			wait(NULL);
		c = NULL;
	}
	else
		_putserr("not found\n", name, c);
}

/**
 * _exe - check
 *
 * @ac: number of arguments
 * @av: array
 * @c: command
 * @name: name file
 * @env: env
 *
 * Return: nothing
 */

void _exe(__attribute__((unused)) int ac, char **av, char *c,
		char *name, char **env)
{
	char *path_file = NULL;

	if (c != NULL)
	{
		if (!_strcmp(c, "cd"))
			_cd(av);
		else if (!_strcmp(c, "setenv") && av[1] != NULL	&& av[2] != NULL)
			_setenv(av);
		else if (!_strcmp(c, "unsetenv") && av[1] != NULL)
			_unsetenv(av);
		else
		{
			path_file = _get_location(c);
			_exe_sub(path_file, av, c, name, env);
			free(path_file);
		}
	}
}
