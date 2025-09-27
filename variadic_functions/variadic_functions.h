#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * print_all - Print values according to a format string.
 * @format: A constant format string with characters:
 *          'c' (char), 'i' (int), 'f' (float), 's' (char *).
 *
 * Description: Prints the arguments in the order they appear in @format.
 *              Unknown specifiers are ignored. Prints "(nil)" for NULL strings.
 *              A newline is printed at the end.
 */
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
