#include <stdio.h>
#include <stdlib.h>

size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *new_ptr;
	int c;
	size_t i = 0;
    if (lineptr == NULL || n == NULL || stream == NULL) 
    {
        return -1;
    }

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
        {
            return -1;
        }
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (i >= *n - 1)
        {

            *n *= 2;
            new_ptr = (char *)realloc(*lineptr, *n);
            if (new_ptr == NULL)
            {
                return -1;
            }
            *lineptr = new_ptr;
        }

        (*lineptr)[i++] = c;

        if (c == '\n')
        {
            break;
	}
    }
     (*lineptr)[i] = '\0';

    if (i == 0 && c == EOF)
    {
        return -1;
    }

    return i;
}
