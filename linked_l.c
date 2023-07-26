#include "monty.h"

/**
 * add_no - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_no(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 * queue_no - adds a node to a stack_t stack in queue_no
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *queue_no(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}


/**
 * free_st - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_st(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}

/**
 * print_st - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_st(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}
