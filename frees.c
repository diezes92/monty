#include "monty.h"

/**
 * free_all_args - Frees all allocated memory for arguments.
 */

void free_all_args(void)
{
	close_stream();
	free_tokens();
	free_arguments();
}

/**
 * free_head - Frees the memory allocated for the head and
 * sets it to NULL.
 */

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);

	arguments->head = NULL;
}

/**
* free_arguments - free memory allocated to arguments pointer
*/

void free_arguments(void)
{
	if (arguments == NULL)
		return;

	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}

	free_head();

	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}

	free(arguments);
}

/**
* free_stack - free the nodes in a stack list
* @head: first node of a dlistint link
* Return: void
*/
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}

/**
 * free_tokens - Frees the allocated memory for tokens.
 */

void free_tokens(void)
{
	int i = 0;

	if (arguments->tokens == NULL)
		return;

	while (arguments->tokens[i])
	{
		free(arguments->tokens[i]);
		i++;
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}
