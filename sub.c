#include "monty.h"
/**
 * sub - subtracts the top element of the stack from the second top element.
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		error_signal = 1;
	}
	else
	{
		tmp = *stack;
		tmp->next->n = tmp->next->n - tmp->n;
		*stack = tmp->next;
		free(tmp);
	}
}
