#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on a format string
 * @format: list of types: 'c', 'i', 'f', 's'
 *
 * Description: If a string is NULL, prints (nil). 
 * Unknown types are ignored. Prints a newline at the end.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *s, *sep = "";

	va_start(ap, format);
	if (format)
		while (format[i])
		{
			if (format[i] == 'c' || format[i] == 'i' ||
			    format[i] == 'f' || format[i] == 's')
			{
				if (format[i] == 'c')
					printf("%s%c", sep, va_arg(ap, int));
				if (format[i] == 'i')
					printf("%s%d", sep, va_arg(ap, int));
				if (format[i] == 'f')
					printf("%s%f", sep, va_arg(ap, double));
				if (format[i] == 's')
				{
					s = va_arg(ap, char *);
					printf("%s%s", sep, s ? s : "(nil)");
				}
				sep = ", ";
			}
			i++;
		}
	printf("\n");
	va_end(ap);
}
