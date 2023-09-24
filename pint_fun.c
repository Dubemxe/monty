#include "monty.h"

/**
 * pint_fun - prints the top of the stack
 * @top: the top of the stack
 * @count: line_number
 * Return: Nothing
*/
void pint_fun(stack_t **top, unsigned int count)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
