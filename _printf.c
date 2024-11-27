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

	va_list args;

	if (!format || !*format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
	{
		i++;
		if (!format[i])
		return (-1);
		count += handle_specifier(format, &i, args);
	}

	else if (format[i] == '\\')
	{
		result = handle_escape(format, &i);
		if (result == -1)
		return (-1);
		count += result;
	}
	else
	{
		count += _putchar(format[i]);
	}
	}

	va_end(args);
	return (count);
}
