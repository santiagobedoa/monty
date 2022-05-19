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
	void (*function)(stack_t **, unsigned int);
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &bufsize, file) != -1)
	{
		if (error_signal == 1)
			break;
		args = split_line(line);
		if (args[0] == NULL || args[0][0] == '#')
		{
			line_number++;
			continue;
		}
		function = get_function(args[0]);
		if (function == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, args[0]);
			error_signal = 1;
			continue;
		}
		function(&stack, line_number);
		line_number++;
		free(args);
	}
	free(line);
	free_stack(&stack);
	fclose(file);
	if (error_signal)
		exit(EXIT_FAILURE);
}
