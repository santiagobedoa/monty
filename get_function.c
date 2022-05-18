#include "monty.h"

/**
 * get_function - returns a pointer to a function if there
 *                is a match beetwen command and built-in func
 * @command: command to be mapped
 *
 * Return: pointer that points to the target function
 */
void (*get_function(char *command))(stack_t **, unsigned int)
{
	int i = 0;

	for (; commands_hashmap[i].opcode != NULL; i++)
	{
		if (strcmp(command, commands_hashmap[i].opcode) == 0)
		{
			return (commands_hashmap[i].f);
		}
	}
	return (NULL);
}
