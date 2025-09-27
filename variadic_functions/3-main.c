#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_all("ceis", 'B', 3, 3.14, "stSchool");
    print_all("sifc", NULL, 42, 2.718, 'H');
    print_all("abcxyz", 'X', 10, "Hello"); /* unknown specifiers are ignored */
    return (0);
}
