#include "monty.h"

/**
 * interpreter - function that open, reads and execute the
 *               commands in the Bytecode file
 * @argv: argument vector - argv[1] is the file to be open
 *
 * Return: void
 */
void interpreter(char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t bufsize = 0;
	char **args;
	void (*function)(stack_t **, unsigned int);
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &bufsize, file) != -1)
	{
		args = split_line(line);
		if (args[1])
		{
			global_number = atoi(args[1]);
			if (global_number == 0 && strcmp(args[1], "0") != 0) /* if n is not a num */
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		function = get_function(args[0]);
		if (function == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
			exit(EXIT_FAILURE);
		}
		function(&stack, line_number);
		line_number++;
		free(args);
	}
	free(line);
	free_stack(&stack);
	fclose(file);
}
