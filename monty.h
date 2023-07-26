#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},	\
			{"pint", pint}, \
			{"pop", pop},	\
			{"swap", swap},	\
			{"add", _add},	\
			{"nop", nop},	\
		{                     \
			NULL, NULL      \
		}                     \
	}

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
* struct help - argument for the current opcode
* @d_struct: stack mode, stack (default) and queue
* @arg: the argument(s) of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int d_struct;
	char *arg;
} help;
help global;

/* stack utility functions available in linked_l.c */
stack_t *add_no(stack_t **stack, const int n);
stack_t *queue_no(stack_t **stack, const int n);
void free_st(stack_t *stack);
size_t print_st(const stack_t *stack);

void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void _add(stack_t **stack, unsigned int line_cnt);
void nop(stack_t **stack, unsigned int line_cnt);

void opcode(stack_t **stack, char *str, unsigned int line_cnt);

int is_digit(char *s);
int isnumber(char *s);
#endif
