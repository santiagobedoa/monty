#include "monty.h"

/**
 * push - function that adds a node to the stack
 * @stack: element at the top of the stack
 * @line_number: line number of the command in the file .m
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (args[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		error_signal = 1;
	}
	else
	{
		global_number = atoi(args[1]);
		new_node = (stack_t *)malloc(sizeof(stack_t));
		if (global_number == 0 && strcmp(args[1],
			"0") != 0 && strcmp(args[1], "-0") != 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			error_signal = 1;
			free(new_node);
		}
		else if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			error_signal = 1;
		}
		else
		{
			new_node->n = global_number;
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
		}
	}
}
