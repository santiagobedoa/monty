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
	stack_t *tmp;

	tmp = *stack;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	tmp->next->prev = NULL;
	tmp->next = NULL;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	*stack = tmp;
	(void)line_number;
}
