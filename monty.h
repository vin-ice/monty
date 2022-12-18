#ifndef MONTY_H
#define MONTY_H

#define BUF_SIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

typedef enum bool {false, true} Boolean;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t; 
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct globals_s - globals
 * @line: current line
 * @head: head of stack 
*/
typedef struct globals_s
{
        unsigned int line;
        stack_t *head;
        FILE *file;
        int STRUCT_MODE;
} globals_t;

extern globals_t globals;

typedef enum {False, True} boolean;

/**utils.c*/
void set_globals(char *);
FILE *get_file(char *);
void free_all(void);
int _isdigit(char *string);
boolean _isascii(int);

/**core - interpreter*/
void interpret(FILE *);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);

/**op_funs.c - operation functions*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t  **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);

/**strings.c*/
int is_int(char *s);
/*errors*/
void err_exit(const char *);
void fatal(const char *, ...);
#endif