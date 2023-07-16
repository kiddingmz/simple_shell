#include "main.h"

/**
 * _strdup - copy string
 *
 * @str: string
 *
 * Return: string
 */

char *_strdup(char *str)
{
	size_t len, i;
	char *string = NULL;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

/**
 * _strtok - breaks a string
 *
 * @str: string
 * @delim: delimiter
 *
 * Return: string
 */
/*
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *string = NULL;
	const char *c;

	if (str)
		token = str;
	while (*token)
	{
		for (c = delim; *c; ++c)
		{
			if (*token == *c)
				break;
		}
		if (!*c)
		{
			break;
		}
		++token;
	}
	if (!*token)
		return (NULL);
	string = token;

	while (*token)
	{
		for (c = delim; *c; ++c)
		{
			if (*token == *c)
				break;
		}
		if (*c)
			break;
		++token;
	}
	if (*token)
		*token++ = '\0';
	return (string);
}

/**
 * _strcat - append a string
 *
 * @dest: destine
 * @src: source
 *
 * Return: string
 */
/*
char *_strcat(char *dest, char *src)
{
	size_t i, n, d;

	d = _strlen(dest);
	n = _strlen(src);
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[d++] = src[i];
	dest[d] = '\0';
	return (dest);
}

/**
 * _strcat_space - append a string
 *
 * @dest: destine
 * @src: source
 *
 * Return: string
 */
/*
char *_strcat_space(char *dest, char *src)
{
	/*
	 *
	size_t i, n, d;

	if (dest != NULL)
		d = _strlen(dest);
	else
		d = 0;
	n = _strlen(src);
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[d++] = src[i];
	dest[d] = 32;
	return (dest);
	*/
	size_t i, n, d;

	d = _strlen(dest);
	n = _strlen(src);
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[d++] = src[i];
	dest[d++] = ' ';
	dest[d] = '\0';
	return (dest);
}

/**
 * _strcpy - copy a string
 *
 * @dest: destine
 * @src: source
 *
 * Return: string
 */
/*
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0 ; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
