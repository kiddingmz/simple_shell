#include "main.h"

/**
 * _exe - execute
 *
 * @ac: number of arguments
 * @av: array
 * @c: command
 * @name: name file
 * @env: env
 *
 * Return: nothing
 */
/*
void _exe(__attribute__((unused)) int ac, char **av, char *c,
		char *name, char **env)
{
	char *path_file = NULL;
	pid_t pid;

	if (c != NULL)
	{
		path_file = _get_location(c);
		if (path_file != NULL)
		{
			pid = fork();
			if (pid == -1)
				exit(1);
			else if (pid == 0)
			{
				if (!_strcmp(c, "env"))
					_putenv(env);
				else
					if (execve(path_file, av, environ) == -1)
						perror(name);
			}
			else
			{
				wait(NULL);
			}
			c = NULL;
		}
		else
		{
			_putstring(c);
			_putstring(": command not found\n");
		}
		free(path_file);
	}
}
