#include "monty.h"

/**
* push_func - function to add a number at the start
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void push_func(stack_t **stack, unsigned int line_number)
{
	unsigned int number;

	if (!_isnumber(globv.n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	number = atoi(globv.n);
	add_element(stack, number);
}

/**
* pall_func - print all the content
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (stack != NULL && tmp != NULL)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* pint_func - print the value at the top of the stack
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void pint_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
* pop_func - deletes the top element of the stack
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void pop_func(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	delete_node_at_index(stack, 0);
}

/**
* swap_func - swaps the two top elements
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *tmpn = NULL, *tmph = *stack;
	unsigned int counter;

	for (counter = 0; tmp != NULL; counter++)
		tmp = tmp->next;

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmpn = tmp->next;
	tmp->next = tmpn->next;
	tmp->prev = tmpn;
	tmpn->next = tmph;
	tmpn->prev = tmph->prev;

	*stack = tmpn;
}
