#include "main.h"

/**
 * _strtrim - remove space in a string
 *
 * @str: string
 *
 * Return: string
 *
 */

char *_strtrim(char *str)
{
	size_t len = _strlen(str);
	size_t start = 0, end = len - 1;

	if (str == NULL)
		return (NULL);
	while (end > 0 && _isspace(str[end]))
		end--;
	if (end == 0 && _isspace(str[end]))
		return (NULL);
	while (_isspace(str[start]))
		start++;
	if (start > 0)
	{
		_memmove(str, str + start, len - start + 1);
		len -= start;
	}
	end = len - 1;
	while (end > 0 && _isspace(str[end]))
		end--;
	str[end + 1] = '\0';
	return (str);
}

/**
 * _strncpy - copy a string
 *
 * @dest: destine
 * @src: source
 * @n: bytes
 *
 * Return: string
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

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
			buffer = _realloc(buffer, input + 1);

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
