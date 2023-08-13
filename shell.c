#include "main.h"

/**
 * mode - mode
 *
 * @ac: number of arguments
 * @av: array
 * @env: env
 *
 * Return: nothing
 */

void mode(int ac, char **av, char **env)
{
	if (ac == 1)
		interactive(ac, av, env);
	else
		non_interactive(ac, av, env);
}

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
	size_t i = 0, line = 1, status = 0;
	ssize_t nu;
	char *buffer = NULL, *tmp_buffer = NULL, *sub_command = NULL;
	char **data = NULL;

	if (isatty(fileno(stdin)))
		mode(ac, av, env);
	else
	{
		while ((nu = getline(&buffer, &i, stdin)) != EOF)
		{
			if (buffer[0] != '\n' && buffer[1] != '\0')
			{
				buffer[nu - 1] = '\0';
				tmp_buffer = buffer;
				buffer = _strtrim(buffer);
				if (buffer == NULL)
					free(tmp_buffer);
				if (buffer != NULL)
				{
					sub_command = _strdup(buffer);
					_strtok(sub_command, " ");
					data = process_args(buffer);
					fflush(stdout);
					status = _exe(ac, data,
							sub_command, av[0],
							env, line++);
					_free_array(data);
				}
			}
			free(sub_command);
			free(data);
		}
		free(buffer);
		exit(status);
	}
	return (0);
}
