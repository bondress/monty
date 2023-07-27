#include "monty.h"

/**
* rotr - rotates the last node of a stack_t stack
* @stack: stack head
* @line_cnt: line count
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int line_cnt)
{
	stack_t *last;
	stack_t *pr;

	(void) line_cnt;
	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;

	while (last->next)
		last = last->next;

	pr = last->prev;
	last->next = *stack;
	last->prev = NULL;
	pr->next = NULL;
	(*stack)->prev = last;
	*stack = last;
}
