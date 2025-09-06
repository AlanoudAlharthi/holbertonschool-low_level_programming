#include "main.h"

/**
 * puts_half - prints second half of a string
 * @str: the string
 */
void puts_half(char *str)
{
	int i, len;

	for (len = 0; str[len] != '\0'; len++)
		;

	i = (len + 1) / 2; /* start index for second half */

	for (; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
