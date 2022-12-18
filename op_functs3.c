#include "monty.h"
/**
 * _pchar - prints the top element
 * @stack: pointer to stack
 * @line_number: line number
*/
void _pchar(stack_t  **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {   
        free_all();
        fatal("L%u: can't pchar, stack empty\n", line_number);
    }
    if (!_isascii((*stack)->n))
    {
        free_all();
        fatal("L%u: can't pchar, value out of range\n", line_number);
    } 
    printf("%c\n", (*stack)->n);
}
/**
 * _pstr - prints the string starting at the top of stack
 * @stack: pointer to stack
 * @line_number: line number
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = NULL;
    (void)line_number;

    for (temp = *stack; temp && temp->n != 0 && _isascii(temp->n); temp = temp->next)
        printf("%c", temp->n);
    printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: line number
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp1 = NULL;
    stack_t *temp2 = NULL;
    (void)line_number;

    if (*stack == NULL)
        return;
    if ((*stack)->next == NULL)
        return;
    
    temp1 = (*stack)->next;
    temp2 = *stack;

    for (; temp2->next != NULL; temp2 = temp2->next)
        ;

    temp1->prev = NULL;
    temp2->next = *stack;
    (*stack)->next = NULL;
    (*stack)->prev = temp2;
    *stack = temp1;
}
