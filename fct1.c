#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the add function is called.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n",
				line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;
	tpb = tpa->next;

	tpb->n = tpa->n + tpb->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the _div function is called.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;
	tpb = tpa->next;

	if (tpa->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpb->n = tpb->n / tpa->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;
	tpb = tpa->next;

	if (tpa->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpb->n = tpb->n % tpa->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	tpa = arguments->head;
	tpb = tpa->next;

	tpb->n = tpb->n * tpa->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * nop - does nothing
 * @stack: Pointer to the stack.
 * @line_number: Line number where the nop function is called.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
