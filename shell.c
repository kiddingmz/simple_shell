#include "main.h"

/**
 * mode - mode
 *
 * @ac: number of arguments
 * @av: array
 *
 * Return: nothing
 */

void mode(int ac, char **av)
{
	if (ac == 1)
		interactive(ac, av);
	else
		non_interactive(ac, av);
}

/**
 * _mode_intern - extra
 *
 * @ac: number of arguments
 * @av: array
 * @buffer: buffer
 * @sub_command: sub command
 * @data: arguments
 * @status: status
 * @nu: number
 * @line: line
 *
 * Return: int
 */

int _mode_intern(int ac, char **av, char *buffer, char *sub_command,
		char **data, size_t *status, ssize_t nu, size_t *line)
{
	buffer[nu - 1] = '\0';
	buffer = _strtrim(buffer);
	if (buffer == NULL)
		return (-1);
	if (buffer != NULL)
	{
		sub_command = _strdup(buffer);
		_strtok(sub_command, " ");
		data = process_args(buffer);
		fflush(stdout);
		*status = _check_command(data);
		if (*status == 1)
			*status = _exe(ac, data, sub_command, av[0], *line++);
		_free_array(data);
		free(sub_command);
		free(data);
	}
	return (*status);
}

/**
 * main - entry point
 *
 * @ac: number of arguments
 * @av: array
 *
 * Return: 0 sucess
 */

int main(int ac, char **av)
{
	size_t i = 0, line = 1, status = 0;
	ssize_t nu;
	char *buffer = NULL, *tmp_buffer = NULL, *sub_command = NULL;
	char **data = NULL;

	if (isatty(fileno(stdin)))
		mode(ac, av);
	else
	{
		while ((nu = getline(&buffer, &i, stdin)) != EOF)
		{
			if (buffer[0] != '\n' && buffer[1] != '\0')
			{
				tmp_buffer = buffer;
				if (_mode_intern(ac, av, buffer, sub_command,
							data, &status, nu, &line) == -1)
					free(tmp_buffer);
			}
			if (status == 2)
				break;
		}
		free(buffer);
		exit(status);
	}
	return (0);
}
