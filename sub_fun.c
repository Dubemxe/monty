#include "monty.h"
/**
 * sub_fun - does subraction to given values
 * @top: a pointer to the top of the stack
 * @count: line number
 *
 * Return: Nothing!
 */
void sub_fun(stack_t **top, unsigned int count)
{
	stack_t *aux;
	int red, Nnodes;

	aux = *top;
	for (Nnodes = 0; aux != NULL; Nnodes++)
		aux = aux->next;
	if (Nnodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	aux = *top;
	red = aux->next->n - aux->n;
	aux->next->n = red;
	*top = aux->next;
	free(aux);
}
