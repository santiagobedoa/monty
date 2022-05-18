#include "monty.h"

/**
 * free_stack -  frees a dlistint_t list.
 * @stack: pointer to a pointer to the head of a list.
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = (*stack);
		(*stack) = tmp->prev;
		free(tmp);
	}
}
