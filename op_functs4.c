#include "monty.h"
/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_number: line number
*/
void _rotr(stack_t  **stack, unsigned int line_number)
{
    stack_t *temp = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	temp = *stack;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: no return
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	globals.STRUCT_MODE = 1;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: no return
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	globals.STRUCT_MODE = 0;
}