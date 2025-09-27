#include "main.h"

/**
 * print_all - prints anything based on a format string
 * @format: list of types of arguments passed
 *          c: char, i: int, f: float, s: char *
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0;
    char *sep = "";
    char *str;

    if (!format)
    {
        printf("\n");
        return;
    }

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's')
        {
            switch (format[i])
            {
                case 'c':
                    printf("%s%c", sep, va_arg(args, int));
                    break;
                case 'i':
                    printf("%s%d", sep, va_arg(args, int));
                    break;
                case 'f':
                    printf("%s%f", sep, va_arg(args, double));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(nil)";
                    printf("%s%s", sep, str);
                    break;
            }
            sep = ", ";
        }
        i++;
    }
    va_end(args);
    printf("\n");
}
