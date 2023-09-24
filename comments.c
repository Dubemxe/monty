#include "monty.h"
/**
 * comments - handles comments
 * @argv: arguments passed
 *
 * Return: Nothing!
 */
void comments(char **argv, unsigned int count)
{
	if (argv[1][0] == '#')
	{
		(void) *argv;
		(void) count;
	}
}
