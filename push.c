#include "monty.h"

/**
 * push -push (add) node to list.
 * @stack: element at the top of the stack.
 * @line_number: constant int value in the structure
 * Return: void
 **/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	printf("hello from push!\n");
	new_node = (stack_t *)malloc(sizeof(stack_t));
	new_node->n = glb_number;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
		*stack = new_node;
	}
	(void)line_number;
}
