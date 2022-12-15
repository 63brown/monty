#include "monty.h"

/**
 * mdf_strtol - wrapper around strtol, handling monty specific errors
 * @num_str: string with potential integer
 * @line_number: line number in bytecode file
 * Return: long int
 */

int mdf_strtol(char *num_str, unsigned int line_number)
{
	int base = 10;
	char *finalptr;
	long value;

	errno = 0;
	value = strtol(num_str, &finalptr, base);

	if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
									|| (errno != 0 && value == 0))
	{
		exit(EXIT_FAILURE);
	}
	if (finalptr == num_str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (num_str[0] != '\0')
		if (!isdigit(num_str[0]) && *finalptr != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	return (value);
}
