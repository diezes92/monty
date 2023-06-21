#include "monty.h"

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pall function is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	if (arguments->head == NULL)
		return;

	(void) line_number;
	(void) stack;

	tp = arguments->head;
	while (tp != NULL)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa;

	(void) stack;
	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;

	if (tpa->n < 0 || tpa->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", tpa->n);
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pint function is called.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}

/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	delete_stack_node();
	arguments->stack_length -= 1;
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	(void) stack;
	(void) line_number;

	tp = arguments->head;

	while (tp != NULL)
	{
		if (tp->n <= 0 || tp->n > 127)
			break;
		printf("%c", tp->n);
		tp = tp->next;
	}

	printf("\n");
}
