#include "monty.h"
/**
 * mul_fun - does multiplication to given values
 * @top: a pointer to the top of the stack
 * @count: line number
 * Return: Nothing!
 */
void mul_fun(stack_t **top, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	aux = head->next->n * head->n;
	head->next->n = aux;
	*top = head->next;
	free(head);
}
