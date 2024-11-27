#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: Format string containing text and specifiers
 *
 * Return: Total number of characters printed
 */

int _printf(const char * const format, ...)
{
	int count = 0, result;
	unsigned int i;
	format_specifier_t specifiers[] =
	{
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_int},
		{'\0', NULL}
	};

	va_list args;

	if (!format || !*format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') /* Gestion des spécificateurs */
	{
		i++;
		if (!format[i])
		return (-1);
		count += handle_specifier(format, &i, args, specifiers);
	}

	else if (format[i] == '\\') /* Gestion des séquences d'échappement */
	{
		result = handle_escape(format, &i);
		if (result == -1)
		return (-1);
		count += result;
	}
	else /* Impression de texte brut */
	{
		count += _putchar(format[i]);
	}
	}

	va_end(args);
	return (count);
}
