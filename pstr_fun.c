#include "monty.h"
/**
 * pstr_fun - prints the string starting at the top of the stack,
 * followed by a new line
 * @top: a pointer to the top of the stack
 * @count: line number
 *
 * Return: Nothing!
 */
void pstr_fun(stack_t **top, unsigned int count)
{
	stack_t *head;
	(void) count;

	head = *top;
	while (head != NULL)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
