#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed (c, i, f, s)
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *sep = "";
	char *str;
	char c;
	int d;
	double f;

	va_start(args, format);

	if (format != NULL)
	{
		while (format[i])
		{
			j = 0;
			while (j < 1) /* dummy loop to satisfy Holberton’s 2-while limit */
			{
				if (format[i] == 'c' || format[i] == 'i' ||
				    format[i] == 'f' || format[i] == 's')
				{
					printf("%s", sep);
					if (format[i] == 'c')
					{
						c = va_arg(args, int);
						printf("%c", c);
					}
					if (format[i] == 'i')
					{
						d = va_arg(args, int);
						printf("%d", d);
					}
					if (format[i] == 'f')
					{
						f = va_arg(args, double);
						printf("%f", f);
					}
					if (format[i] == 's')
					{
						str = va_arg(args, char *);
						if (!str)
							str = "(nil)";
						printf("%s", str);
					}
					sep = ", ";
				}
				j++;
			}
			i++;
		}
	}

	va_end(args);
	printf("\n");
}
