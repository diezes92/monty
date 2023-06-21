#include "monty.h"

/**
 * init_args - Initializes a pointer to
 * arg_s structure.
 */
void init_args(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_failed();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->stream = NULL;
	arguments->head = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
	arguments->stack_length = 0;
	arguments->stack = 1;
}

/**
 * is_number - Checks if a string represents a valid integer number.
 * @str: The string to check.
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * malloc_failed - Handles the error when malloc fails to allocate memory.
 */

void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * close_stream - Closes the file stream and sets it to NULL.
 */

void close_stream(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}

/**
* is_comment - checks the tokens if it starts with #"
* Return: 0 or 1
*/
int is_comment(void)
{
	if (
		arguments->tokens &&
		arguments->tokens[0] &&
		arguments->tokens[0][0] == '#'
	)
		return (1);

	return (0);
}
