#include "main.h"
/**
 * own_exit - exits the shell
 * @args: input parameter
 * Return: 1 on success
 */

int own_exit(char **args)
{
	if (strcmp(args[0], "exit") == 0)
		exit(0);
	return (1);
}

/**
 * own_env - prints environment
 * @args: input parameter
 * Return: 1 on success
 */
int own_env(char **args)
{
	unsigned int i;

	if (strcmp(args[0], "env") == 0)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (0);
	}
	return (1);
}
