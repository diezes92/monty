#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	arguments->stack = 1;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the sub function is called.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;
	tpb = tpa->next;

	tpb->n = tpb->n - tpa->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the swap function is called.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;
	tpb = tpa->next;
	tpa->next = tpb->next;
	if (tpa->next)
		tpa->next->prev = tpa;
	tpb->next = tpa;
	tpa->prev = tpb;
	tpb->prev = NULL;
	arguments->head = tpb;
}

