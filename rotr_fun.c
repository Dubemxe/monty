#include "monty.h"
/**
* rotr_fun - rotates the stack to the bottom
* @top: a pointer to the top of the stack
* @count: line number
* Return: Nothing!
*/
void rotr_fun(stack_t **top, __attribute__((unused)) unsigned int count)
{
	stack_t *copy;

	copy = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *top;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*top)->prev = copy;
	(*top) = copy;
}
