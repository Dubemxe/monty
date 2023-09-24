#include "monty.h"
/**
 * rotl_fun - rotates the stack to the top
 * @top: a pointer to the top of the stack
 * @count: line number
 *
 * Return: Nothing!
 */
void rotl_fun(stack_t **top,  __attribute__((unused)) unsigned int count)
{
	stack_t *temp = *top, *aux;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	aux = (*top)->next;
	aux->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = temp;
	(*top) = aux;
}
