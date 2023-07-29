#include "main.h"

static char *last_input;

/**
 * find_in_path - find the path
 *
 * @command: command
 *
 * Return: pointer
 */

char *find_in_path(char *command)
{
	struct stat st;
	int stat_ret, i;
	char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

	path = _getenv("PATH");
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		_memset(buf, 0, PATH_MAX_LENGTH);
		_strcpy(buf, dir[i]);
		_strcat(buf, "/");
		_strcat(buf, command);
		stat_ret = stat(buf, &st);
		if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_array(dir);
			ret = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!ret)
				return (NULL);
			strcpy(ret, buf);
			return (ret);
		}
	}
	if (stat_ret == -1)
		free_array(dir);
	return (NULL);
}


/**
 * _getinput - read line
 *
 * Return: Pointer
 */

char *_getinput(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

	do {
		_putstring("$ ");
		fflush(stdout);
		nread = getline(&input, &input_size, stdin);
		if (nread == -1)
		{
			free(input);
			_putstring("\n");
			return (NULL);
		}
		input[nread - 1] = '\0';
	} while (input[0] == '\0' || isspace(input[0]));
	last_input = input;
	return (input);
}

/**
 * free_last_input - free last input
 *
 * Return: nothing
 */

void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}

/**
 * __getline - read input stdin
 *
 * Return: pointer
 */

void *__getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_pos, buf_size;
	char *input_str = NULL;
	char current_char;
	int input_len = 0;

	while (1)
	{
		if (buf_pos >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_size == 0)
				return (input_str);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buf_pos];

		buf_pos++;

		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = current_char;
			input_len++;
		}
	}
}

/**
 * _getenv - get env
 *
 * @name: name of env
 *
 * Return: pointer
 */

char *_getenv(const char *name)
{
	char **env;
	size_t name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}
