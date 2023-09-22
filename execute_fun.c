#include "monty.h"
/**
* execute - executes the opcode
* @content: line content
* @stack: top of the linked list
* @file: a pointer to the monty file
* @count: line counter
* Return: Nothing
*/
int execute(char *content, stack_t **stack, FILE *file, unsigned int count)
{
	instruction_t opst[] = {
			{"push", push_fun}, {"pall", pall_fun},
	};

	unsigned int i = 0;
	char *opc;

	opc = strtok(content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	jos.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opc)
	{
		if (strcmp(opc, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (opc && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: invalid instruction %s\n", count, opc);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
