#include <string.h>
#include "monty.h"

/**
 * swap -  swaps data from top to previous
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *t = NULL;
	int t_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	t_n = t->n;
	t->n = t_n;

	t->n = t->next->n;
	t->next->n = t_n;
}
