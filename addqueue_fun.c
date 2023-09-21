#include "monty.h"
/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @top: a pointer to the top of the stack
 * Return: no return
*/
void addqueue(stack_t **top, int n)
{
	stack_t *new_node, *mut;

	mut = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (mut)
	{
		while (mut->next)
			mut = mut->next;
	}
	if (!mut)
	{
		*top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		mut->next = new_node;
		new_node->prev = mut;
	}
}
