#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *top)
{
	stack_t *mut;

	mut = top;
	while (top)
	{
		mut = top->next;
		free(top);
		top = mut;
	}
}
