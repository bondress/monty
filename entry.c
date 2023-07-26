#define  _POSIX_C_SOURCE 200809L
#include <string.h>
#include "monty.h"

void file_error(char *argv);
void error_usage(void);
int status = 0;

/**
 * main - entry point
 * @argv: list of arguments passed to program
 * @argc: amount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.d_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}
	}
	free(buffer);
	free_st(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by main()
 *
 * Desc: prints message if file cannot be opened
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints usage message and exits
 *
 * Desc: prints message if user does not give any
 * file or more than one argument to your program
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
