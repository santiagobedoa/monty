#include "monty.h"


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
	return (commands_hashmap[0].f);
}
