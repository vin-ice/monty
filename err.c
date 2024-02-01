#include "monty.h"
/**
 * err_exit - prints errors to stdout and exits program
 * @msg: message to output
 */
void err_exit(const char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
/**
 * fatal - prints general errors to stderr and exits
 * @format: Message Format
 */
void fatal(const char *format, ...)
{
	va_list va;

	va_start(va, format);
	vfprintf(stderr, format, va);
	va_end(va);
	exit (EXIT_FAILURE);
}

