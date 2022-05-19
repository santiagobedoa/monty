#include "monty.h"

/**
 * pop - function that deletes the value at top of stack
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		error_signal = 1;
	}
	else
	{
		*stack = (*stack)->prev;
		if ((*stack) != NULL)
		{
			(*stack)->next = NULL;
		}
		free(tmp);
	}
}
