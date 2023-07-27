#include "monty.h"

/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *c = *stack;

	while (c)
	{
		if (c->n <= 0 || c->n > 127)
			break;
		putchar((char) c->n);
		c = c->next;
	}
	putchar('\n');
}
