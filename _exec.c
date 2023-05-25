#include "main.h"

/**
 * execute_command - Execute a command.
 * @command: The name of the command to execute.
 * @argv: An array of arguments for the command.
 * @envp: The environment variables.
 * @path: The PATH environment variable.
 * Return: void.
 */
int execute_command(char *command, char **argv, char **envp, char *path)
{
	char *full_path = NULL;
	pid_t child_pid = 0;
	int status;

	full_path = search_path(command, full_path, path);
	if (full_path != NULL)
	{
		_exec(full_path, child_pid, status, argv, envp);
	}
	else
	{
		if (access(command, X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(command, argv, envp) == -1)
				{
					perror("Failed to execute command");
				}
				exit(EXIT_FAILURE);
			}
			else
				wait(&status);
		}
		else
		{
			perror("Command not found");
		}
	}
	free(full_path);
	return (1);
}

/**
 * _exec - execute command
 * @full_path: command fullpath
 * @child_pid: process id
 * @status: check status
 * @argv: argument vector
 * @envp: environment variable
 */
void _exec(char *full_path, pid_t child_pid,
		int status, char **argv, char **envp)
{
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(full_path, argv, envp) == -1)
		{
			perror("Failed to execute command");
		}
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
