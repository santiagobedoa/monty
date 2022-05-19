#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;

	tmp = *stack;
	new = *stack;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	(*stack)->prev->next = NULL;
	*stack = (*stack)->prev;
	tmp->prev = new;
	new->next = tmp;
	new->prev = NULL;
	(void)line_number;
}
