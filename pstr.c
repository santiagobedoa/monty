#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: element at the top of the stack (head)
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n >= 127)
		{
			break;
		}
		printf("%c", (char)temp->n);
		temp = temp->prev;
	}
	printf("\n");
	(void)line_number;
}
