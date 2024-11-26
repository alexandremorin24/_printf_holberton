#include "main.h"

void _printf(const char * const format, ...)
{
    int count = 0;
	format_specifier_t specifiers[] = {
		{'c', print_char},
        {'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
        {'i', print_int},
		{'\0', NULL}
	};
    va_list args;
    unsigned int i = 0, j = 0;
    va_start(args, format);

    if (!format || !format[i])
    return (-1);

    for (; format[i] != '\0'; i++)

    if (format[i] == '%')
    {
        i++;
        if (!format[i])
        {
            va_end(args);
            return (-1);
        }
        for (j = 0; specifiers[j].spec != '\0'; j++)
        {
            if (specifiers[j].spec  == format[i])
            {
                count += specifiers[j].func(args);
                break;
            }
        }
          if (specifiers[j].spec == '\0')
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
    }
    va_end(args);
    return(count);
}

