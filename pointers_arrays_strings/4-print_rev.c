#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	i--; /* عد المؤشر إلى آخر حرف قبل نهاية السلسلة */

	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}

	_putchar('\n');
}
