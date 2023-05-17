#include "main.h"

/**
 * exec_cmd - map if command is a builtin or a process
 * @args: command and its flags
 * @envp: environment variables
 *
 * Return: 1 on success, 0 otherwise
 */
int exec_cmd(char **args, char **envp)
{
	unsigned int i, j;
	char *path = NULL;
	size_t num_builtins;	
	Command builtin_commands[] = {
		{"env", &own_env},
		{"exit", &own_exit}
	};
	static char *cached_path = NULL;
	if (cached_path == NULL)
	{
		for (i = 0; envp[i] != NULL; i++)
		{
			if (strncmp(envp[i], "PATH=", 5) == 0)
			{
				cached_path = envp[i] + 5;
				break;
			}
		}
	}	
	num_builtins = sizeof(builtin_commands) / sizeof(builtin_commands[0]);
	j = 0;
	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; j < num_builtins; j++)
	{
		if (strcmp(args[0], builtin_commands[j].name) == 0)
		{
			return ((*builtin_commands[j].func)(args));
		}
	}
	path = cached_path;
	return (execute_command(args[0], args, envp, path));
}
