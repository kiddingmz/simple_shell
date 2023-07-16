#include "main.h"

/**
 * interactive - interactive mode
 *
 * @ac: number of arguments
 * @av: array
 * @env: env
 *
 * Return: nothing
 */

void interactive(int ac, char **av, char **env)
{
	ssize_t num_buffer;
	size_t size_buffer;
	char *command = NULL;
	char *sub_command = NULL;
	char **data = NULL;
	
	while (1)
	{
		_putstring("$ ");
		num_buffer = getline(&command, &size_buffer, stdin);
		if (num_buffer == -1)
		{
			if (command != NULL)
				free(command);
			_putchar('\n');
			exit(0);
		}
		if (command[0] != '\n' && command[1] != '\0')
		{
			command[num_buffer - 1] = '\0';
			command = _strtrim(command);
			if (command != NULL)
			{
				if (!_strcmp(command, "exit"))
				{
					free(command);
					exit(127);
				}

				sub_command = _strdup(command);
				 _strtok(sub_command, " ");
				data = process_args(command);
				fflush(stdout);
				_exe(ac, data, sub_command, av[0], env);
				_free_array(data);
				free(sub_command);
			}
		}
	}
}

/**
 * non_interactive - non-interactive mode
 *
 * @ac: number of arguments
 * @av: array
 * @env: env
 *
 * Return: nothing
 */

void non_interactive(int ac, char **av, char **env)
{
	char **data = NULL;
	char *dat = NULL;

	if (ac > 1)
	{
		dat = _cpy_arg(av);
		data = process_args(dat);
		_exe(ac, data, av[1], av[0], env);
		free(dat);
		_free_array(data);
		dat = NULL;
		data = NULL;
	}
}
