#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed
 *   c: char, i: integer, f: float, s: char *
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(args, format);

	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (format[i] == 'c')
				printf("%s%c", sep, va_arg(args, int));
			if (format[i] == 'i')
				printf("%s%d", sep, va_arg(args, int));
			if (format[i] == 'f')
				printf("%s%f", sep, va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", sep, str);
			}
			sep = ", ";
			i++;
		}
	}

	va_end(args);
	printf("\n");
}
