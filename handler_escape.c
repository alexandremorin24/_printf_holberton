#include "main.h"

/**
 * handle_escape - Processes escape sequences in a format string.
 * @format: The format string being processed.
 * @i: Pointer to the current index in the format string.
 *
 * Description: This function handles escape sequences that begin with
 * a backslash (`\`) in the format string. It advances the index to the
 * character following the backslash and processes known escape sequences
 * such as `\n`, `\t`, and others. If the escape sequence is not valid,
 * it prints the backslash and the invalid character as-is.
 *
 * Return: The number of characters printed for the escape sequence.
 *         Returns -1 if the format string ends abruptly after a backslash.
 */

int handle_escape(const char *format, unsigned int *i)
{
	(*i)++;

	if (!format[*i])
		return (-1);

	switch (format[*i])
	{
		case 'n':
			return (_putchar('\n'));
		case 't':
			return (_putchar('\t'));
		case '\\':
			return (_putchar('\\'));
		case '\'':
			return (_putchar('\''));
		case '\"':
			return (_putchar('\"'));
		default:
			_putchar('\\');
			return (_putchar(format[*i]) + 1);
	}
}
