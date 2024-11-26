#include "main.h"

/**
 * handle_escape_sequence - Handles escape sequences like \n, \t, etc.
 * @c: The character after the backslash (\).
 *
 * Return: The number of characters printed (1 if the escape sequence
 *         was valid, 2 if printed as-is, or -1 on error).
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
