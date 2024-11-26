#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: Format string containing text and specifiers
 *
 * Return: Total number of characters printed
 */
int _printf(const char * const format, ...)
{
    int count = 0, result = 0;
	format_specifier_t specifiers[] = {
		{'c', print_char},
        {'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
        {'i', print_int},
		{'\0', NULL}
	};
    va_list args;
    unsigned int i, j;
    
    if (!format || !*format)
    return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {


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
		else if (format[i] == '\\')
		{
			i++;

			if (!format[i])
			{
				va_end(args);
				return (-1);
			}

			result = handle_escape_sequence(format[i]);

			if (result == -1)
			{
				va_end(args);
				return (-1);
			}

			count += result;
		}
        else
        {
            count += _putchar(format[i]);
        }

    }
    va_end(args);
    return(count);
}
