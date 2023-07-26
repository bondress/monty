#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * pchar - prints the integer at the top of the stack as character
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
