#ifndef MONTY_H
#define MONTY_H

/* ---LIBRARIES--- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global_number;

/* ---GLOBAL VARS--- */
#define TOK_DELIM " \t\r\n\a$"

/* ---STRUCTURES--- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* ---PROTOTYPES--- */
void interpreter(char *argv[]);
char **split_line(char *line);
void (*get_function(char *command))(stack_t **, unsigned int);
int execute_args(char **args);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);


static const instruction_t commands_hashmap[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

#endif
