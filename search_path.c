#include "main.h"
/**
 * search_path - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *search_path(char *command, char *fullpath, char *path)
{
	unsigned int command_len, path_len, original_path_len;
	char *path_cpy, *token;

	command_len = _strlen(command);
	original_path_len = _strlen(path);
	path_cpy = malloc(sizeof(char) * original_path_len + 1);
	if (!path_cpy)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(path_cpy, path);
	/* copy PATH directory + command name and check if it exists */
	token = strtok(path_cpy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_len = _strlen(token);
		fullpath = malloc(sizeof(char) * (path_len + command_len) + 2);
		if (!fullpath)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(fullpath, token);
		fullpath[path_len] = '/';
		_strcpy(fullpath + path_len + 1, command);
		fullpath[path_len + command_len + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_cpy);
	return (fullpath);
}
