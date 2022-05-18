#include "monty.h"

/**
 * pall - Function that print the elements of a stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	printf("this is pall\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
