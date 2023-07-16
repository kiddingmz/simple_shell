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
/*
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
/*
ssize_t _getline(char **line_pointer, size_t *n, FILE *stream)
{
	ssize_t bytes_read, buffer_size, read_bytes = 0;
	static char *buffer;
	char *buffer_loc = NULL;

	if (line_pointer == NULL || n == NULL || stream == NULL)
		return (-1);
	if (buffer == NULL || *n == 0)
	{
		buffer_size = 120;
		buffer = allocator(buffer_size);
		if (buffer == NULL)
			return (-1);
	}
	else
		buffer_size = *n;
	buffer_loc = buffer;
	while ((bytes_read = read(fileno(stream), buffer_loc, 1)) > 0)
	{
		read_bytes++;
		if (read_bytes >= buffer_size)
		{
			buffer_size *= 2;
			buffer = _realloc(buffer, buffer_size);
			if (buffer == NULL)
				return (-1);
			buffer_loc = buffer + read_bytes;
		}
		if (buffer[read_bytes - 1] == '\n')
			break;
		buffer_loc++;
	}
	if (bytes_read == -1 || bytes_read == 0)
	{
		free(buffer);
		*line_pointer = NULL;
		*n = 0;
		return (-1);
	}
	buffer[read_bytes] = '\0';
	*line_pointer = buffer;
	*n = buffer_size;
	return (read_bytes);
}

/**
 * process_args - process arguments
 *
 * @data: data
 *
 * Return: matrix
 */
/*
char **process_args(char *data)
{
	char *tmp = NULL;
	char *str_tmp = NULL;
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
