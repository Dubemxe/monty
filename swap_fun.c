#include "monty.h"
/**
 * swap_fun - swaps the top two elements of the stack
 * @top: a pointer to the top of the stack
 * @count: line number
 *
 * Return: Nothing!
 */
void swap_fun(stack_t **top, unsigned int count)
{
	stack_t *head;
	int len = 0, aux;

	head = *top;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	head = *top;
	aux = head->n;
	head->n = head->next->n;
	head->next->n = aux;
}
