#include "main.h"

/**
 * print_char - Function to print a single letter
 * @args: va_list containing the argument for the letter
 *
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}