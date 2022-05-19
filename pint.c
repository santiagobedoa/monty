#include "monty.h"

/**
 * pint -  prints the value at the top of the stack
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp != NULL)
	{
		printf("%d\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		error_signal = 1;
	}
}
