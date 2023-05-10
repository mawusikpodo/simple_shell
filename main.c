#include "main.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * @envp: evironment variable
 * Return: Always 0.
 */

int main(int argc, char **argv __attribute__((unused)), char **envp)
{
	if (argc == 1)
		prompt(envp);
	return (0);
}
