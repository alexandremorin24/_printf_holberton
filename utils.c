#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string to measure
 *
 * Description: This function traverses the string until it reaches
 * the null character to count the number of characters.
 *
 * Return: The length of the string
 */

int _strlen(char *s)
{
int count = 0;
while (s[count] != '\0')
{
count++;
}
return (count);
}

#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
