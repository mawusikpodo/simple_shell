#include "main.h"

#define BUF_SIZE 64

/**
 * allocate_tokens - Allocates memory for the tokens array.
 *
 * @size: Size of the tokens array to allocate.
 *
 * Return: A pointer to the allocated memory.
 */
char **allocate_tokens(int size)
{
	char **tokens = malloc(size * sizeof(char *));

	if (!tokens)
	{
		perror("allocation error in allocate_tokens()");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	return (tokens);
}

/**
 * reallocate_tokens - Reallocates memory for the tokens array.
 *
 * @tokens: Pointer to the tokens array.
 * @size: Pointer to the size of the tokens array.
 *
 * Return: A pointer to the reallocated memory.
 */
char **reallocate_tokens(char **tokens, int *size)
{
	*size += BUF_SIZE;
	tokens = realloc(tokens, *size * sizeof(char *));
	if (!tokens)
	{
		perror("reallocation error in reallocate_tokens(): tokens");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	return (tokens);
}

/**
 * tokenize - Tokenizes the input string.
 *
 * @line: Pointer to the input string to tokenize.
 *
 * Return: A pointer to the tokens array.
 */
char **tokenize(char *line)
{
	int size = BUF_SIZE;
	int index = 0;
	char **tokens = allocate_tokens(size);
	char *token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}

		tokens[index] = token;
		index++;

		if (index >= size)
		{
			tokens = reallocate_tokens(tokens, &size);
		}

		token = strtok(NULL, TOK_DELIM);
	}

	tokens[index] = NULL;
	return (tokens);
}
