#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on a format string
 * @format: list of types: 'c', 'i', 'f', 's'
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *s, *sep = "";

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, va_arg(ap, int));
			sep = ", ";
			break;
		case 'i':
			printf("%s%d", sep, va_arg(ap, int));
			sep = ", ";
			break;
		case 'f':
			printf("%s%f", sep, va_arg(ap, double));
			sep = ", ";
			break;
		case 's':
			s = va_arg(ap, char *);
			printf("%s", sep);
			switch (s == NULL)
			{
			case 0:
				printf("%s", s);
				break;
			default:
				printf("(nil)");
				break;
			}
			sep = ", ";
			break;
		default:
			break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
