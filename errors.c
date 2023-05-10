#include "main.h"

#define NUM_ERRORS 5

const char * const ERROR_MESSAGES[NUM_ERRORS] = {
	"",	/* dummy entry to offset error codes */
	"Error: fork failed\n",
	"Error: execve failed\n",
	"Error: malloc failed\n",
	"Error: empty path\n"
};

/**
 * errors - prints errors
 * @error: error number
 * Return: void
 */
void errors(int error)
{
	if (error < 1 || error >= NUM_ERRORS)
		return;	/* unknown error code */

	write(STDERR_FILENO, ERROR_MESSAGES[error], strlen(ERROR_MESSAGES[error]));
	if (error == 1 || error == 2)
		perror("Error");
}

/**
 * print_error - output error
 * @progname: name of command
 * @msg: message to be printed
 * Return: void
 */
void print_error(const char *progname, char *msg)
{
	int progname_len = strlen(progname);
	int msg_len = strlen(msg);

	write(STDERR_FILENO, progname, progname_len);
	write(STDERR_FILENO, msg, msg_len);
}
