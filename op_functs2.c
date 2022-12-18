#include "monty.h"
/**
 * _nop - doesn't do anything
 * @stack: pointer to stack
 * @line_number: line number
*/
void _nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * _sub - subtracts the top element from the second element
 * @stack: pointer to stack
 * @line_number: line number
*/
void _sub(stack_t  **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *temp = NULL;

    temp = *stack;
    for (; temp != NULL; temp = temp->next, count++)
        ;
    if (count < 2)
    {   
        free_all(); 
        fatal("L%u: can't sub, stack too short\n", line_number);
    }
    temp = *stack;
    temp->next->n -= temp->n;
    _pop(stack, line_number);

}
/**
 * _div - divides the top element from the second element
 * @stack: pointer to stack
 * @line_number: line number
*/
void _div(stack_t  **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *temp = NULL;

    temp = *stack;
    for (; temp != NULL; temp = temp->next, count++)
        ;
    
    if (count < 2)
    {   
        free_all(); 
        fatal("L%u: can't div, stack too short\n", line_number);
    }
    
    if ((*stack)->n == 0)
	{
		free_all();
		fatal("L%u: division by zero\n", line_number);
	}

    temp = *stack;
    temp->next->n /= temp->n;
    _pop(stack, line_number);
}
/**
 * _mul - multiplies the top element from the second element
 * @stack: pointer to stack
 * @line_number: line number
*/
void _mul(stack_t  **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *temp = NULL;

    temp = *stack;
    for (; temp != NULL; temp = temp->next, count++)
        ;
    if (count < 2)
    {   
        free_all(); 
        fatal("L%u: can't div, stack too short\n", line_number);
    }
    temp = *stack;
    temp->next->n *= temp->n;
    _pop(stack, line_number);
}
/**
 * _mod - finds the dividen of the top element
 *  from the second element
 * @stack: pointer to stack
 * @line_number: line number
*/
void _mod(stack_t  **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *temp = NULL;

    temp = *stack;
    for (; temp != NULL; temp = temp->next, count++)
        ;

    if (count < 2)
    {   
        free_all(); 
        fatal("L%u: can't div, stack too short\n", line_number);
    }

    if (temp->n == 0)
	{
		free_all();
		fatal("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

    temp = *stack;
    temp->next->n %= temp->n;
    _pop(stack, line_number);
}