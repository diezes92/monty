#include "monty.h"

/**
 * check_args - Checks the number of command-line arguments.
 * @argc: The number of command-line arguments.
 */

void check_args(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
* delete_stack_node - delete node at the head/top
* Return: void
*/
void delete_stack_node(void)
{
	stack_t *tp;

	tp = arguments->head;
	arguments->head = tp->next;
	free(tp);
}

/**
 * tok_l - Tokenizes the line read from file.
 */

void tok_l(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(linecpy, arguments->line);
	arguments->n_tokens = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->n_tokens += 1;
		token = strtok(NULL, delims);
	}

	arguments->tokens = malloc(sizeof(char *) *
			(arguments->n_tokens + 1));
	strcpy(linecpy, arguments->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->tokens[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (arguments->tokens[i] == NULL)
			malloc_failed();
		strcpy(arguments->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	arguments->tokens[i] = NULL;
	free(linecpy);
}
