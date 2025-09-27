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
    char *str;
    char *sep = "";

    va_start(args, format);
    if (format)
        while (format[i])
        {
            if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's')
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
                    if (!str)
                        str = "(nil)";
                    printf("%s%s", sep, str);
                }
                sep = ", ";
            }
            i++;
        }
    va_end(args);
    printf("\n");
}
