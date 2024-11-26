#include "main.h"

/**
 * print_percent - Prints a '%' character.
 * @args: The va_list (not used in this function).
 *
 * Return: Always returns 1 (one character printed).
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_decimal - Prints an integer in decimal format.
 * @args: The va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_decimal(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}

	else
	{
		num = n;
	}

	if (num / 10 != 0)
		count += print_decimal_recursive(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * print_int - Prints an integer using print_decimal.
 * @args: The va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 *
 * Description: This function is a wrapper around print_decimal
 * because the 'i' specifier behaves the same as the 'd' specifier.
 */

int print_int(va_list args)
{
    return (print_decimal(args));
}
