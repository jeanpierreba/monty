#include "monty.h"

/**
* add_func - add the two top elements
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int counter, numbertmp;

	for (counter = 0; tmp != NULL; counter++)
		tmp = tmp->next;

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	numbertmp = (*stack)->n;
	delete_node_at_index(stack, 0);
	(*stack)->n += numbertmp;
}

/**
* nop_func - doesn't do anything
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* sub_func - subtracts the top element from the second top
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int counter, numbertmp;

	for (counter = 0; tmp != NULL; counter++)
		tmp = tmp->next;

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	numbertmp = (*stack)->n;
	delete_node_at_index(stack, 0);
	(*stack)->n -= numbertmp;
}

/**
* mul_func - multiplies the two top elements
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int counter, numbertmp;

	for (counter = 0; tmp != NULL; counter++)
		tmp = tmp->next;

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	numbertmp = (*stack)->n;
	delete_node_at_index(stack, 0);
	(*stack)->n *= numbertmp;
}
