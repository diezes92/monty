#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->n_tokens <= 1 || !(is_number(arguments->tokens[1])))
	{
		free_arguments();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(arguments->tokens[1]);
	if (arguments->head == NULL)
		arguments->head = *stack;
	else
	{
		if (arguments->stack)
		{
			(*stack)->next = arguments->head;
			arguments->head->prev = *stack;
			arguments->head = *stack;
		}
		else
		{
			stack_t *tp = arguments->head;

			while (tp->next)
				tp = tp->next;
			tp->next = *stack;
			(*stack)->prev = tp;
		}
	}
	arguments->stack_length += 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	arguments->stack = 0;
}

/**
 * rotl - rotates the stack to the top
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tpa, *tpb;

	(void) stack;
	(void) line_number;
	if (arguments->stack_length < 2)
		return;

	tpa = arguments->head;
	tpb = tpa->next;
	arguments->head = tpb;
	while (tpb)
	{
		if (tpb->next == NULL)
		{
			tpb->next = tpa;
			tpa->next = NULL;
			tpa->prev = tpb;
			break;
		}

		tpb = tpb->next;
	}
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tp, *lt;

	(void) stack;
	(void) line_number;
	if (arguments->stack_length < 2)
		return;

	tp = arguments->head;
	while (tp)
	{
		if (tp->next == NULL)
		{
			lt = tp;
			break;
		}
		tp = tp->next;
	}

	lt->prev->next = NULL;
	lt->next = arguments->head;
	lt->prev = NULL;

	arguments->head = lt;
}
