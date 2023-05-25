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
 * read_line - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *read_line(void)
{
	int bufsize = 1024, i = 0, character;
	char *line = malloc(sizeof(char) * bufsize);

	if (line == NULL)
	{
		perror("allocation error in read_stream");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar(); /* read first char from stream */
		if (character == EOF)
		{
			line[i] = '\0';
			break;
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			break;
		}
		else
		{
			line[i] = character;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += 1024;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				perror("reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
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

	while (1)
	{
		print_prompt();
		if (isatty(STDIN_FILENO) == 1)
			line = read_command();
		else
			line = read_line();

		args = tokenize(line);
		exec_cmd(args, envp);
		free(line);
		free(args);
	}
}
