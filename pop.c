#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
* pop - pops the very top element of the stack
* @stack: stack given by main
* @line_cnt: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *t = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	t = (*stack)->next;
	free(*stack);
	*stack = t;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
