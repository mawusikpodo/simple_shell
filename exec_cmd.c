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

	char *builtin_func_list[] = {
		"env",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&own_env,
		&own_exit
	};
	/* Find the PATH environment variable */
	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break;
		}
	}

	j = 0;
	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; j < sizeof(builtin_func_list) / sizeof(char *); j++)
	{
		if (strcmp(args[0], builtin_func_list[j]) == 0)
		{
			return ((*builtin_func[j])(args));
		}
	}
	return (execute_command(args[0], args, envp, path));
}
