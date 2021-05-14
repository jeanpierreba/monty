#include "monty.h"

/**
* get_op - select the operator to call a function
* @opcode: string we want to evaluate to get the operator
* Return: 0 on success, exit if it get a invalid instruction
*/

int get_op(char *opcode)
{
	int i;
	instruction_t op[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"mul", mul_func},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode && opcode; i++)
		if (!strcmp(opcode, op[i].opcode))
		{
			op[i].f(&(globv.head), globv.line_number);
			return (0);
		}

	fprintf(stderr, "L%d: unknown instruction %s\n", globv.line_number, opcode);
	exit(EXIT_FAILURE);
}
