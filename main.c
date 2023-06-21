#include "monty.h"

arg_t *arguments = NULL;

/**
 * main - Entry point
 * @argc: The number of command-line arguments.
 * @argv: A pointer to an array of strings containing
 * the command-line arguments.
 * Description: print alphabets in lowercase using the putchar
 *
 * Return: returns 0 (Success)
 */
int main(int argc, char **argv)
{
	size_t nb = 0;

	check_args(argc);
	init_args();
	get_strm(argv[1]);

	while (getline(&arguments->line, &nb, arguments->stream) != -1)
	{
		arguments->line_number += 1;
		tok_l();
		get_instruction();
		run_instruction();
		free_tokens();
	}

	close_stream();
	free_arguments();

	return (0);
}
