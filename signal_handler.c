#include "main.h"

/**
 * handle_sigint - signal Ctrl + C
 *
 * @sig: signal number
 *
 * Return: Nothing
 */

void handle_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	_putstring("$ ");
	fflush(stdout);
}

/**
 * handle_sigquit - signal Ctrl + \
 *
 * @sig: signal number
 *
 * Return: Nothing
 */

void handle_sigquit(int sig)
{
	(void) sig;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - signal Ctrl+Z
 *
 * @sig: signal number
 *
 * Return: Nothing
 */

void handle_sigstp(int sig)
{
	(void) sig;
	_putstring("\n");
	_putstring("$ ");
	fflush(stdout);
}
