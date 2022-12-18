#include "monty.h"
/**
 * _push - adds a node to stack
 * @stack: pointer to stack
 * @line_number: line number
*/
void _push(stack_t **stack, unsigned int line_number)
{
    char *num;
    stack_t *node = NULL, *tm = *stack;

    printf("\n===op_funcs.c->_push====\n");
    num = strtok(NULL, " \t\n");
    if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
    {    
        free_all();
        fatal("L%u: usage: push integer\n", line_number);
    }

    node = malloc(sizeof (stack_t));
    if (node == NULL)
    {   
        free_all(); 
        err_exit("malloc");
    }
    node->n = atoi(num);
    if (globals.STRUCT_MODE == 0)
        node->prev = NULL;
    node->next = *stack;
    if (globals.STRUCT_MODE == 0 || !*stack)
	{
		node->next = *stack;
		node->prev = NULL;
		if (*stack)
			(*stack)->prev = node;
		*stack = node;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = node;
		node->prev = tm;
		node->next = NULL;
	}
}
/**
 * _pall - prints all values in stack
 * @stack: pointer to stack list
 * @line_number: line number
*/
void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *node = *stack;

    printf("\n===op_funcs.c->_pall====\n");
    if (!node)
        return;
    while (node)
    {
        printf("%d\n", node->n);
        node = node->next;
    }
    (void)line_number;
}
/**
 * _pop - removes the top element of the stack
 * @stack: pointer to stack list
 * @line_number: line number
*/
void _pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = NULL;

    printf("\n===op_funcs.c->_pop====\n");
    if (stack == NULL || *stack == NULL)
    {    
        free_all();
        fatal("L%u: can't pop an empty stack", line_number);
    }

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
/**
 * _swap - swaps the top two elements
 * @stack: pointer to stack list
 * @line_number: line number
*/
void _swap(stack_t **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *temp = NULL;

    printf("\n===op_funcs.c->_swap====\n");
    temp = *stack;
    for (; temp != NULL; temp = temp->next, count++)
        ;
    if (count < 2)
    {   
        free_all(); 
        fatal("L%u: can't swap, stack too short\n", line_number);
    }

    temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;
    (*stack)->prev = NULL;
}
/**
 * _add - adds the top two elements
 * @stack: pointer to stack list
 * @line_number: line number
*/
void _add(stack_t **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *temp = NULL;

    printf("\n===op_funcs.c->_add====\n");
    temp = *stack;
    for (; temp != NULL; temp = temp->next, count++)
        ;
    if (count < 2)
    {   
        free_all(); 
        fatal("L%u: can't add, stack too short\n", line_number);
    }
    
    temp = *stack;
    temp->next->n += temp->n;
    _pop(stack, line_number);
}