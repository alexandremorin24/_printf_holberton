#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_decimal(va_list args);
int print_int(va_list args);
int _putchar(char c);
int _strlen(char *s);
int handle_escape_sequence(char c);

/**
 * struct format_specifier - Struct linking a format specifier to its function
 * @spec: The format specifier character (e.g., 'c', 's', 'd', etc.)
 * @func: Pointer to the function handling the given specifier
 *
 * Description: This structure is used in _printf to associate a
 * format specifier character with the corresponding function
 * that processes and prints the argument for that specifier.
 */

typedef struct format_specifier
{
	char spec;
	int (*func)(va_list args);
} format_specifier_t;

#endif
