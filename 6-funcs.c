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

