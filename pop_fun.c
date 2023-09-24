#include "monty.h"
/**
 * pop_fun - removes the top of the stack
 * @top: the top of the stack
 * @count: line number
 *
 * Return: Nothing!
 */
void pop_fun(stack_t **top, unsigned int count)
{
	stack_t *head;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u:  can't pop an empty stack\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	head = *top;
	*top = head->next;
	free(head);
}
