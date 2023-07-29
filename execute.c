#include "main.h"

/**
 * _execute - execute comands
 *
 * @argv: arguments
 *
 * Return: int
 */

int _execute(char **argv)
{
	pid_t id;
	int status = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (status);
	if (_check_command(argv))
		return (status);

	id = fork();
	if (id < 0)
	{
		_puterror("fork");
		return (1);
	}
	if (id == -1)
		perror(argv[0]), free_array(argv), free_last_input();
	if (id == 0)
	{
		envp[0] = _getenv("PATH");
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = find_in_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]), free_array(argv), free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
