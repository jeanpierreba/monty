#ifndef monty_H
#define monty_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globalizator - helps to make global variables
 * @head: head of the stack
 * @line_number: track of the line of the opcode
 * @buffer: buffer where we save the data
 * @n: value
 * @fptr: pointer to the file descriptor
 */

typedef struct globalizator
{
	stack_t *head;
	unsigned int line_number;
	char *buffer;
	char *n;
	FILE *fptr;
} global_variables;

extern global_variables globv;

int get_op(char *opcode);
void set_to_global(void);
void push_func(stack_t **stack, unsigned int line_number);
stack_t *add_element(stack_t **head, unsigned int n);
void free_stack(stack_t *head);
int _isnumber(char *s);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
int delete_node_at_index(stack_t **head, unsigned int index);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);

#endif
