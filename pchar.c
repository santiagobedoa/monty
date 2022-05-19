#include "monty.h"

/**
 * pchar - prints the corresponding char of the element at the top of a stack
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		error_signal = 1;
	}
	else
	{
		if ((*stack)->n <= 0 || (*stack)->n >= 127)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			error_signal = 1;
		}
		else
		{
			printf("%c\n", (char)(*stack)->n);
		}
	}
}
