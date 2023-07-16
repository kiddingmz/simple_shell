#include "main.h"

/**
 * _cpy_arg - copy arguments
 *
 * @data: matrix
 *
 * Return: string
 *
 */

char *_cpy_arg(char **data)
{
	size_t i, size, j;
	char *arg = NULL;

	if (data == NULL)
		return (NULL);
	size = 0;
	for (i = 1; data[i] != NULL; i++)
		size += _strlen(data[i]);

	/*arg = malloc(sizeof(char) * (size + i));*/
	arg = allocator(size + i);
	if (arg == NULL)
		return (NULL);

	for (j = 0; j < (size + i); j++)
		arg[j] = '\0';
	j = 1;
	while (j < i)
	{
		_strcat_space(arg, data[j]);
		j++;
	}
	return (arg);
}

/**
 * _atoi - convert string to int
 *
 * @s: string
 *
 * Return: int
 */
/*
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = d = n = len = f = 0;
	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);
	return (n);
}

/**
 * _memcpy - copy to another pointer
 *
 * @dest: destine
 * @src: source
 * @n: size
 *
 * Return: string
 *
 */
/*
char *_memcpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _memmove - move to onother pointer
 *
 * @dest: destine
 * @src: source
 * @n: size
 *
 * Return: string
 *
 */
/*
char *_memmove(char *dest, const char *src, size_t n)
{
	if ((src == NULL) || (dest == NULL))
		return (NULL);
	if ((src < dest) && (dest < src + n))
	{
		dest += n;
		src += n;
		while (n--)
			*--dest = *--src;
	}
	else
	{
		while (n--)
			*dest++ = *src++;
	}
	return (dest);
}

/**
 * _isspace - check space in a string
 *
 * @c: char
 *
 * Return: int
 *
 */
/*
int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f')
		return (1);
	return (0);
}
