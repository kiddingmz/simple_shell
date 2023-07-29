#include "main.h"

void _exe(void);

/**
 * _exe - interactive mode
 *
 * Return: nothing
 */

void _exe(void)
{
	char *input;
	char **args;
	int status;

	do {
		input = _getinput();
		if (!input || !*input)
			break;

		args = tokenize_input(input);
		if (!args || !*args)
		{
			free(input);
			free_array(args);
			continue;
		}
		status = _execute(args);
		free(input);
		free_array(args);
		status = 1;
	} while (status);
}

/**
 * main - test shell
 *
 * @argc: argc
 * @argv: argv
 *
 * Return: int
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	size_t i;
	ssize_t nu;
	char *buffer = NULL;
	char **args;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	if (isatty(fileno(stdin)))
	{
		if (argc == 1)
			_exe();
	}
	else
	{
		while ((nu = _getline(&buffer, &i, stdin)) != -1)
		{
			args = tokenize_input(buffer);
			if (!args || !*args)
			{
				free(buffer);
				free_array(args);
				continue;
			}
			_execute(args);
			free(buffer);
			free_array(args);
		}
	}
	return (EXIT_SUCCESS);
}
