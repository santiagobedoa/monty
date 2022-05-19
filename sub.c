#include "monty.h"

/**
 * sub - function that subs the top two elements of a stack
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		error_signal = 1;
	}
	else
	{
		(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
		pop(stack, line_number);
	}
}
