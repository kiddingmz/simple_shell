#include "main.h"

/**
 * assign_lineptr - lineptr variable for _getline
 *
 * @lineptr: input
 * @n:size
 * @buffer: buffer
 * @b: size of buffer
 *
 * Return: nothing
 */

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - input data
 *
 * @lineptr: input
 * @n: size
 * @stream: stream
 *
 * Return: ssize_t
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = allocator(120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buffer = __realloc(buffer, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_lineptr(lineptr, n, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}

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
 * __realloc - realloc space
 *
 * @src: source
 * @size: new size
 *
 * Return: string
 */

char *__realloc(char *src, size_t size)
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

