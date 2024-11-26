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

#include "main.h"

/**
 * print_string - Function to print a string
 * @args: va_list containing the argument of type char *
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
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
