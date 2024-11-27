#include "main.h"

int handle_specifier(const char *format, unsigned int *i, va_list args,
		format_specifier_t specifiers[])
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
