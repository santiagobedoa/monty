#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element.
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error_signal = 1;
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_signal = 1;
	}
	else
	{
		tmp->prev->n = tmp->prev->n / tmp->n;
		pop(stack, line_number);
	}
}
