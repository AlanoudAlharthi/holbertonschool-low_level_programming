#include "main.h"

/**
 * print_number - print a long integer using _putchar
 * @n: number to print
 *
 * Return: void
 */
static void print_number(long n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_number(n / 10);
	_putchar((char)(n % 10 + '0'));
}

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 *
 * Description: Numbers are separated by a comma and a space,
 * and the sequence ends with 98 followed by a new line.
 *
 * Return: void
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i < 98; i++)
		{
			print_number((long)i);
			_putchar(',');
			_putchar(' ');
		}
		print_number(98L);
		_putchar('\n');
	}
	else
	{
		for (i = n; i > 98; i--)
		{
			print_number((long)i);
			_putchar(',');
			_putchar(' ');
		}
		print_number(98L);
		_putchar('\n');
	}
}
