#include "main.h"

/**
 * main - entry point
 *
 * @ac: number of arguments
 * @av: array
 * @env: env
 *
 * Return: 0 sucess
 */

int main(int ac, char **av, char **env)
{
	size_t i;
	ssize_t nu;
	char *buffer = NULL;
	char *sub_command = NULL;
	char **data = NULL;

	if (isatty(fileno(stdin)))
	{
		if (ac == 1)
			interactive(ac, av, env);
		else
			non_interactive(ac, av, env);
	}
	else
	{
		while ((nu = _getline(&buffer, &i, stdin)) != -1)
		{
			if (buffer[0] != '\n' && buffer[1] != '\0')
			{
				buffer[nu - 1] = '\0';
				buffer = _strtrim(buffer);
				if (buffer != NULL)
				{
					sub_command = _strdup(buffer);
					_strtok(sub_command, " ");
					data = process_args(buffer);
					fflush(stdout);
					_exe(ac, data, sub_command, av[0], env);
					_free_array(data);
				}
			}
			free(sub_command);
			buffer = NULL;
			sub_command = NULL;
			data = NULL;
		}
	}
	return (0);
}
