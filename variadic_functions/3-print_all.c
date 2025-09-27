#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a char
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything based on format string
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *sep = "";

	typedef struct printer
	{
		char type;
		void (*f)(va_list);
	} printer_t;

	printer_t printers[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	va_start(args, format);

	if (format != NULL)
	{
		while (format[i])
		{
			int j = 0;
			if (format[i] == 'c' || format[i] == 'i' ||
			    format[i] == 'f' || format[i] == 's')
			{
				printf("%s", sep);
				while (printers[j].type)
				{
					if (printers[j].type == format[i])
					{
						printers[j].f(args);
						break;
					}
					j++;
				}
				sep = ", ";
			}
			i++;
		}
	}

	va_end(args);
	printf("\n");
}
