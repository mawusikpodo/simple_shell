#include "main.h"

/**
 * print_prompt - prints prompt to console
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		_puts("($) ");
}

/**
 * read_command - reads in user input and tokenizes it
 *
 * Return: line buffer
 */
char *read_command(void)
{
	char *line = NULL;
	size_t linesize = 0;
	ssize_t nread = getline(&line, &linesize, stdin);

	if (nread == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("error reading line from stdin");
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	return (line);
}

/**
 * prompt - main prompt function
 * @envp: environment variables
 */
void prompt(char **envp)
{
	char *line = NULL;
	char **args;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			print_prompt();
			line = read_command();
			args = tokenize(line);
			exec_cmd(args, envp);
			free(line);
			free(args);
		}
	}
	else
	{
		size_t bufsize = 0;
		ssize_t nread;

		while ((nread = getline(&line, &bufsize, stdin)) != -1)
		{
			if (nread > 0 && line[nread - 1] == '\n')
				line[nread - 1] = '\0';
			args = tokenize(line);
			exec_cmd(args, envp);
			free(line);
			free(args);
			line = NULL;
		}
		if (line != NULL)
			free(line);
	}
}
