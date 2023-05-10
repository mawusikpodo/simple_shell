#include "main.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	var_length = _strlen(variable);
	if (var_length != length)
		return (-1);

	i = 0;
	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * up to given length are the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * _strlen - Check description
 * @s: Input parameter
 * Description: Returns the length of a string
 * Return: Always 0
 */
size_t _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
