#include "main.h"

/**
 * free_error - free allocaded memomry
 *
 * @argv: argv
 * @arg: arg
 *
 * Return: nothing
 */

void free_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * free_array - free memory
 *
 * @ptr: pointer
 *
 * Return: nothing
 */

void free_array(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}


/**
 * free_path - free global env
 *
 * Return: Nothing
 */

void free_path(void)
{
	if (environ != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}

/**
 * tokenize - parsing user input
 *
 * @str: string
 * @delim: delimiter
 *
 * Return: pointer to pointer
 */

char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **retur = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		retur = realloc(retur, sizeof(char *) * (i + 1));
		if (retur == NULL)
			return (NULL);

		retur[i] = malloc(_strlen(token) + 1);
		if (!(retur[i]))
			return (NULL);

		_strcpy(retur[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	retur = realloc(retur, (i + 1) * sizeof(char *));
	if (!retur)
		return (NULL);

	retur[i] = NULL;
	return (retur);
}

/**
 * tokenize_input - splits a user input
 *
 * @input: string
 *
 * Return: pointer to pointer
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_putstring("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
