#include "monty.h"

/**
 * push - function that adds a node to the stack
 * @stack: element at the top of the stack
 * @line_number: line number of the command line in the file .m
 *
 * Return: void
 */
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
