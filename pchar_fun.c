#include "monty.h"
/**
 * pchar_fun - prints the char at the top of the stack
 * @top: a pointer to the top of the stack
 * @count: line number
 *
 * Return: Nothing!
 */
void pchar_fun(stack_t **top, unsigned int count)
{
	stack_t *head;

	head = *top;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
                fclose(jos.file);
                free(jos.content);
                free_stack(*top);
                exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
