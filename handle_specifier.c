#include "main.h"

static const format_specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_int},
		{'\0', NULL}
	};

/**
 * handle_specifier - Processes a format specifier in the format string.
 * @format: The format string containing the text and specifiers.
 * @i: Pointer to the current index in the format string.
 * @args: The list of variadic arguments to process.
 *
 * Description: This function identifies the format specifier at the current
 * position in the format string, retrieves the corresponding function from
 * the specifiers table, and calls it to process the associated argument.
 * If the specifier is not recognized, it prints '%' followed by the unknown
 * specifier character. The index is not automatically advanced; the caller
 * is responsible for managing it.
 *
 * Return: The number of characters printed, or -1 if an error occurs.
 */

int handle_specifier(const char *format, unsigned int *i, va_list args)
{
	int j, count = 0;

	for (j = 0; specifiers[j].spec != '\0'; j++)
	{
		if (specifiers[j].spec == format[*i])
		{
			count += specifiers[j].func(args);
			return (count);
		}
	}

	count += _putchar('%');
	count += _putchar(format[*i]);

	return (count);
}
