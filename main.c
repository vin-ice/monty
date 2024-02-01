#include "monty.h"

globals_t globals;

/**
 * main - starts Monty
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0
 */
int main(int argc, char **argv)
{

	if (argc != 2)/**file not passed or multiple args*/
		err_exit("USAGE: monty file");

	set_globals(argv[1]);

	interpret(globals.file);
	free_all();
	return (0);
}

