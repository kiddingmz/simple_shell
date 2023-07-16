#include "main.h"

/**
 * _strcmp - compare two strings
 *
 * @dest: destine
 * @src: source
 *
 * Return: int
 */

int _strcmp(const char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (dest[i] || src[i])
	{
		if (dest[i] == src[i])
			i++;
		else
			break;
	}

	if (dest[i] == '\0' && src[i] == '\0')
		return (0);
	return (1);
}*/

/**
 * _getenv - get path
 *
 * @name: name of path
 *
 * Return: string
 */
/*
char *_getenv(char *name)
{
	char *sub_path = NULL;
	size_t i, j;

	if (name != NULL || (name[0] != '\n' && name[1] != '\0'))
	{
		i = 0;
		while (environ[i])
		{
			sub_path = environ[i];
			j = 0;
			while (sub_path[j] != '=' && sub_path[j] == name[j]
					&& sub_path[j] != '\0' && name[j] != '\0')
				j++;
			if (name[j] == '\0')
				return (sub_path);
			i++;
		}
	}
	return (NULL);
}
*/
/**
 * _get_location - get location
 *
 * @name: name
 *
 * Return: string
 */
/*
char *_get_location(char *name)
{
	char *path = _getenv("PATH");
	char *o_path = NULL;
	char *p_path = _strdup(path);
	char *buffer = allocator(256);

	if (check_path(name) == 1)
	{
		_memcpy(buffer, name, _strlen(name));
		free(p_path);
		return (buffer);
	}
	_strtok(p_path, "=");
	o_path = _strtok(NULL, ":");
	while (o_path)
	{
		_strcat_path(o_path, name, buffer);
		if (check_path(buffer) == 1)
		{
			free(p_path);
			return (buffer);
		}
		o_path = _strtok(NULL, ":");
	}
	free(p_path);
	return (NULL);
}
*/

/**
 * _strlen -length of string
 *
 * @str: string
 *
 * Return: unsigned int
 */
/*
size_t _strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * _strcat_path - concat two strings
 *
 * @dest: destine
 * @src: source
 * @buffer: buffer
 *
 * Return: nothing
 */
/*
void _strcat_path(const char *dest, const char *src, char *buffer)
{
	size_t d = _strlen(dest);
	size_t i = 0;

	_strcpy(buffer, dest);
	buffer[d++] = '/';
	while (src[i])
	{
		buffer[d] = src[i];
		d++;
		i++;
	}
	buffer[d] = '\0';
}
