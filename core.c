#include "monty.h"
/**
 * interpreter - interpretes bytecodes from file passed
 * @file: file containing bytecodes 
 */
void interpret(FILE *file)
{
	char buf[BUF_SIZE];
	void (*f)(stack_t **stack, unsigned int line_number);
	char *opcode = NULL;

	/**
	  head = malloc(sizeof (stack_t));
	  if (head == NULL)
	  {
	  free_all();
	  err_exit("malloc failed");
	  }*/

	for(globals.line = 1; fgets(buf, BUF_SIZE, file) != NULL; globals.line++)
	{
		opcode = strtok(buf, " \r\t\n");
		if (opcode != NULL && opcode[0] != '#')
		{
			f = get_op_func(opcode);
			f(&(globals.head), globals.line); /**execute*/
		}
	}
}
/**
 * get_op_func - selects the correct operation toperform
 * @s: operation to perform
 *
 * Return: pointer to the correct function
 */
void (*get_op_func(char *s))(stack_t ** , unsigned int)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			break;
		i++;
	}
	if (ops[i].opcode == NULL)
	{
		free_all();
		fatal("L%u: unknown instruction %s\n", globals.line, s);
	}
	return (ops[i].f);
}

