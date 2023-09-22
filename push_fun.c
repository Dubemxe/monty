#include "monty.h"
/**
 * push_fun - adds a new element to the stack
 * @top: a pointer to the top of the stack
 * @count: list_number
 * Return: Nothing!
 */
void push_fun(stack_t **top, unsigned int count)
{
	int n;
       	int i = 0, flag = 0;

	if (jos.arg)
	{
		if (jos.arg[0] == '-')
			i++;
		for (; jos.arg[i] != '\0'; i++)
		{
			if (jos.arg[i] > 57 || jos.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(jos.file);
			free(jos.content);
			free_stack(*top);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(jos.file);
		free(jos.content);
		free_stack(*top);
		exit(EXIT_FAILURE); }
	n = atoi(jos.arg);
	if (jos.lifi == 0)
		addnode(top, n);
	else
		addqueue(top, n);
}
