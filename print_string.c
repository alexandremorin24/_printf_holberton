#include "main.h"

/**
 * print_string - Function to print a string
 * @args: va_list containing the argument of type char *
 *
 * Return: The number of characters printed
 */
int print_string(va_list args);
{
    char *str = va_arg(args, char *)
    int count = 0;

    if (str == NULL)
    {
        str = "(null)";
    }
    for (; *str != '\0'; str++)
    {
        count += _putchar(*str);
    }
    return (count);
}