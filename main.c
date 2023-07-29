#include "main.h"

/**
 * main - test shell
 *
 * Return: int
 */

int main(void)
{
	char *input;
	char **args;
	int status;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

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

	return (EXIT_SUCCESS);
}
