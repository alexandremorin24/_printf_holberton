#include "main.h"

/**
 * handle_escape - Handles escape sequences in a format string.
 * @format: The format string being processed.
 * @i: Pointer to the current index in the format string.
 *
 * Return: The number of characters printed for the escape sequence,
 * or -1 if an error occurs.
 */
int handle_escape(const char *format, unsigned int *i)
{
	int result;

	(*i)++;

	if (!format[*i])
		return (-1);

	result = handle_escape_sequence(format[*i]);

	return (result);
}

/**
 * handle_escape_sequence - Handles individual escape sequences.
 * @c: The character following the backslash (\).
 *
 * Return: The number of characters printed (1 if the escape sequence
 *         is valid, 2 if printed as-is, or -1 on error).
 */
int handle_escape_sequence(char c)
{
	switch (c)
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
			_putchar(c);
			return (2);
	}
}
