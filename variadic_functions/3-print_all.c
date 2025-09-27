#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_string - prints a string or (nil) if NULL
 * @s: string to print
 */
void print_string(char *s)
{
	if (s == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", s);
}

/**
 * print_all - prints anything based on a format string
 * @format: list of types: 'c', 'i', 'f', 's'
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *sep = "";

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(ap, int));
				break;
			case 'i':
				printf("%s%d", sep, va_arg(ap, int));
				break;
			case 'f':
				printf("%s%f", sep, va_arg(ap, double));
				break;
			case 's':
				printf("%s", sep);
				print_string(va_arg(ap, char *));
				break;
			default:
				i++;
				continue;
		}
		sep = ", ";
		i++;
	}

	printf("\n");
	va_end(ap);
}
