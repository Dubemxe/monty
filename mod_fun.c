#include "monty.h"
/**
 * mod_fun - gets the modulus of given values
 * @top: a pointer to the top of the stack
 * @count; LINE NUMBER
 *
 * Return: Nothing!
 */
void mod_fun(stack_t **top, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	aux = head->next->n % head->n;
	head->next->n = aux;
	*top = head->next;
	free(head);
}
