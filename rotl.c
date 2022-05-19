#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));
	new->n = (*stack)->n;
	tmp = *stack;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	new->prev = NULL;
	new->next = tmp;
	tmp->prev = new;
	pop(stack, line_number);
}
