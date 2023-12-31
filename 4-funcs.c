#include "main.h"

/**
 * allocator - allocate memory
 *
 * @n: size
 *
 * Return: pointer
 */

char *allocator(size_t n)
{
	size_t i;
	char *buff = malloc(sizeof(char) * (n + 1));

	if (!buff)
	{
		perror("allocate error");
		return (NULL);
	}

	for (i = 0; i <= n; i++)
		buff[i] = '\0';
	return (buff);
}

/**
 * _realloc - realloc space
 *
 * @src: source
 * @size: new size
 *
 * Return: string
 */

char *_realloc(char *src, size_t size)
{
	char *dest;
	size_t i = 0;

	if (src == NULL)
		return (allocator(size));
	if (size == 0)
	{
		free(src);
		return (NULL);
	}
	dest = allocator(size);
	if (dest == NULL)
	{
		free(src);
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	return (dest);
}

/**
 * _getline - input data
 *
 * @line_pointer: input
 * @n: size
 * @stream: stream
 *
 * Return: ssize_t
 */

ssize_t _getline(__attribute__((unused))char **line_pointer,
		__attribute__((unused))size_t *n,
		__attribute__((unused))FILE * stream)
{
	return (0);
}

/**
 * process_args - process arguments
 *
 * @data: data
 *
 * Return: matrix
 */

char **process_args(char *data)
{
	char *tmp = NULL, *str_tmp = NULL;
	char **all_args = NULL;
	size_t k, i = 0, num_args = 0, arg_len = 0;

	if (data == NULL)
		return (NULL);
	tmp = _strdup(data);
	str_tmp = _strtok(tmp, " ");
	while (str_tmp != NULL)
	{
		num_args++;
		str_tmp = _strtok(NULL, " ");
	}
	all_args = malloc(sizeof(char *) * (num_args + 1));
	if (all_args == NULL)
	{
		free(tmp);
		return (NULL);
	}
	str_tmp = _strtok(data, " ");
	while (str_tmp != NULL && i < num_args)
	{
		arg_len = _strlen(str_tmp);
		all_args[i] = malloc(arg_len + 1);
		if (all_args[i] == NULL)
		{
			_free_array(all_args);
			free(all_args);
			free(tmp);
			return (NULL);
		}
		for (k = 0; k < arg_len; k++)
			all_args[i][k] = str_tmp[k];
		all_args[i][arg_len] = '\0';
		str_tmp = _strtok(NULL, " ");
		i++;
	}
	all_args[i] = NULL;
	free(tmp);
	return (all_args);
}
