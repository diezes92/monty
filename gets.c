#include "monty.h"

/**
 * invalid_instruction - Handles an unknown instruction error.
 */

void invalid_instruction(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			arguments->line_number, arguments->tokens[0]);
	free_all_args();
	exit(EXIT_FAILURE);
}

/**
 * get_instruction - Sets the instruction based on the first token
 * in the input line.
 */

void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"nop", &nop}, {"add", &add},
		{"pall", &pall}, {"sub", &sub},
		{"div", &_div}, {"mul", &mul},
		{"rotl", &rotl}, {"rotr", &rotr},
		{"stack", &stack}, {"queue", &queue},
		{"pstr", &pstr}, {"pchar", &pchar},
		{"mod", &mod},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0) /* no instructions */
		return;
	if (arguments->tokens[0][0] == '#')
	{
		arguments->instruction->opcode = "nop";
		arguments->instruction->f = nop;
		return;
	}
	for (; instructions[i].opcode != NULL; i++)
	{
		/* compare opcode of instruction to first token (instruct..) */
		if (strcmp(instructions[i].opcode, arguments->tokens[0])
				== 0)
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 * get_strm_fail - Handles the error when reading a file fails.
 * @fileName: The name of the file that failed to open.
 */

void get_strm_fail(char *fileName)
{
	dprintf(2, "Error: Can't open file %s\n", fileName);
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * get_strm - gets the stream for reading from the specified file.
 * @fileName: Name of the file to open and set as the stream.
 */

void get_strm(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		get_strm_fail(fileName);

	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		get_strm_fail(fileName);
	}
}

/**
 * run_instruction - Runs the instruction specified by the arguments.
 */

void run_instruction(void)
{
	stack_t *stack = NULL;

	if (arguments->n_tokens == 0)
		return;

	arguments->instruction->f(&stack, arguments->line_number);
}
