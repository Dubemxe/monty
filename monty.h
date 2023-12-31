#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct jos_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct jos_s
{
        char *arg;
        FILE *file;
        char *content;
        int lifi;
} jos_t;
extern jos_t jos;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push_fun(stack_t **top, unsigned int count);
void pall_fun(stack_t **top, unsigned int count);
void addqueue(stack_t **top, int n);
void addnode(stack_t **top, int n);
void free_stack(stack_t *top);
int execute(char *content, stack_t **stack, unsigned int count, FILE *file);
void pint_fun(stack_t **top, unsigned int count);
void pop_fun(stack_t **top, unsigned int count);
void swap_fun(stack_t **top, unsigned int count);
void add_fun(stack_t **top, unsigned int count);
void nop_fun(stack_t **top, unsigned int count);
void sub_fun(stack_t **top, unsigned int count);
void div_fun(stack_t **top, unsigned int count);
void mul_fun(stack_t **top, unsigned int count);
void mod_fun(stack_t **top, unsigned int count);
void pchar_fun(stack_t **top, unsigned int count);
void pstr_fun(stack_t **top, unsigned int count);
void rotl_fun(stack_t **top, __attribute__((unused)) unsigned int count);
void rotr_fun(stack_t **top, __attribute__((unused)) unsigned int count);
void stack_fun(stack_t **top, unsigned int count);
void queue_fun(stack_t **top, unsigned int count);
#endif /*MONTY_H*/
