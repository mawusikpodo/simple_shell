#include "main.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0.
 */

int main(int argc, char **argv __attribute__((unused)))
{
	if (argc == 1)
		prompt(environ);
	return (0);
}
