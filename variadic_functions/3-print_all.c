#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *sep = "";
	char *str;

	va_start(args, format);

	if (format != NULL)
	{
		while (format[i])
		{
			if (format[i] == 'c' || format[i] == 'i' ||
			    format[i] == 'f' || format[i] == 's')
			{
				printf("%s", sep);
				if (format[i] == 'c')
					printf("%c", va_arg(args, int));
				if (format[i] == 'i')
					printf("%d", va_arg(args, int));
				if (format[i] == 'f')
					printf("%f", va_arg(args, double));
				if (format[i] == 's')
				{
					str = va_arg(args, char *);
					if (!str)
						str = "(nil)";
					printf("%s", str);
				}
				sep = ", ";
			}
			i++;
		}
	}

	va_end(args);
	printf("\n");
}
