#include "monty.h"
/**
 * pall_fun - prints the stack
 * @top: a pointer to the top of the stack
 * @count: not used
 *
 * Return: Nothing!
 */
void pall_fun(stack_t **top, unsigned int count)
{
	stack_t *head;
	(void)count;

	head = *top;
	if (head == NULL)
		return;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
