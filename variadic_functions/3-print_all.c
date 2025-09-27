#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on a format string
 * @format: list of argument types ('c', 'i', 'f', 's')
 *
 * Rules:
 * - Ignore any other characters.
 * - If a string is NULL, print "(nil)".
 * - Separate printed items with ", " (no separator before the first).
 * - Print a newline at the end.
 * - No for/goto/ternary operators. Max 2 while, 2 if.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *s;
	int printed = 0; /* 0 = no item printed yet, 1 = at least one printed */

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			if (printed)
				printf(", ");
			printf("%c", va_arg(ap, int));
			printed = 1;
			break;
		case 'i':
			if (printed)
				printf(", ");
			printf("%d", va_arg(ap, int));
			printed = 1;
			break;
		case 'f':
			if (printed)
				printf(", ");
			printf("%f", va_arg(ap, double));
			printed = 1;
			break;
		case 's':
			if (printed)
				printf(", ");
			s = va_arg(ap, char *);
			if (!s)
				s = "(nil)";
			printf("%s", s);
			printed = 1;
			break;
		default:
			break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
