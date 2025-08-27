#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase,
 * followed by a new line. Only putchar is allowed.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char ch;

	for (num = 0; num < 10; num++)
		putchar(num + '0');

	for (ch = 'a'; ch <= 'f'; ch++)
		putchar(ch);

	putchar('\n');

	return (0);
}
