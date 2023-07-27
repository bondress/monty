#include "monty.h"

/**
* rotl - rotates the first element of the stack
* @stack: stack head
* @line_cnt: line count
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_cnt)
{
	stack_t *l;
	stack_t *r;

	(void) line_cnt;
	if (!stack || !*stack || !(*stack)->next)
		return;

	l = r = *stack;

	while (r->next)
		r = r->next;
	r->next = l;
	l->prev = r;
	*stack = l->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
