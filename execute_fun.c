#include "monty.h"
/**
* execute - executes the opcode
* @content: line content
* @stack: top of the linked list
* @file: a pointer to the monty file
* @count: line counter
* Return: Nothing
*/
int execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
			{"push", push_fun}, {"pall", pall_fun},
			{"pint", pint_fun}, {"pop", pop_fun},
			{"swap", swap_fun}, {"add", add_fun},
			{"nop", nop_fun}, {"sub", sub_fun},
			{"div", div_fun}, {"mul", mul_fun},
			{"mod", mod_fun}, {"pchar", pchar_fun},
			{"pstr", pstr_fun}, {"rotl", rotl_fun},
			{"rotr", rotr_fun}, {"stack", stack_fun},
			{"queue", queue_fun},
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
