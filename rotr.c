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
	stack_t *temp = *stack, *new;

	if (*stack && (*stack)->next)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		new = malloc(sizeof(stack_t));
		new->n = temp->n;
		temp->prev->next = NULL;
		free(temp);
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	(void)line_number;
}
