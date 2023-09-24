#include "monty.h"
#include "main.h"
jos_t jos = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments passed
 * @argv: location of the monty file
 *
 * Return: Always 0 (SUCCESS)
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	unsigned int count = 0;
	ssize_t reader = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	jos.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (reader > 0)
	{
		content = NULL;
		reader = my_getline(&content, &size, file);
		jos.content = content;
		count++;
		if (reader > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
