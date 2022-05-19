#include "monty.h"

/**
 * swap - function that swaps the top 2 elements of stack
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 **/
void swap(stack_t **stack, unsigned int line_number)
{
	int n_tmp = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		error_signal = 1;
	}
	else
	{
		n_tmp = (*stack)->n;
		(*stack)->n = (*stack)->prev->n;
		(*stack)->prev->n = n_tmp;
	}
}
