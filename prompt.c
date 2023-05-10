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
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error reading line from stdin");
			exit(EXIT_FAILURE);
		}
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
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar(); /* read first char from stream */
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = character;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
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
	}
	free(line);
	free(args);
}
