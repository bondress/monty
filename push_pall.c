#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
        char *n = global.arg;

        if ((is_digit(n)) == 0)
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
                exit(EXIT_FAILURE);
        }

        if (global.d_struct == 1)
        {
                if (!add_no(stack, atoi(global.arg)))
                {
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                if (!queue_no(stack, atoi(global.arg)))
                {
                        exit(EXIT_FAILURE);
                }
        }
}

/**
 * pall - prints the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
        print_st(*stack);
}
