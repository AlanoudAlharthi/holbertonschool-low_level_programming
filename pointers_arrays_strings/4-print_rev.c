#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string
 *
 * Description: This function prints the string pointed to by s
 *              in reverse order using _putchar.
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	i--; /* move to the last character before '\0' */

	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}

	_putchar('\n');
}
