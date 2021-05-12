#include "monty.h"

/**
* _isnumber - check is the value passed is a number
* @s: value passed
* Return: 1 if is a number, 0 otherwise
*/

int _isnumber(char *s)
{
	if (s == NULL)
		return (0);

	if (*s == '-')
		s++;

	for (; *s != '\0'; s++)
		if (isdigit(*s) == '\0')
			return (0);
	return (1);
}

/**
* free_stack - frees a stack_t
* @head: head of the doubly linked list
*/

void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
