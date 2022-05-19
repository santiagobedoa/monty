#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element.
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error_signal = 1;
	}
	else
	{
		(*stack)->prev->n = (*stack)->prev->n * (*stack)->n;
		pop(stack, line_number);
	}
}
