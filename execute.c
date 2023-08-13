#include "main.h"

/**
 * _exe - execute
 *
 * @ac: number of arguments
 * @av: array
 * @c: command
 * @name: name file
 * @env: env
 * @line: line execute
 *
 * Return: exit status
 */

int _exe(__attribute__((unused)) int ac, char **av, char *c,
		char *name, char **env, int line)
{
	char *path_file = NULL;
	pid_t pid;
	int status = 0;

	if (c != NULL)
	{
		path_file = _get_location(c);
		if (path_file != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				free(path_file);
				exit(1);
			}
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
				free(path_file);
			}
			c = NULL;
		}
		else
		{
			_flush_err(name, c, line);
			status = 127;
		}
	}
	return (status);
}
