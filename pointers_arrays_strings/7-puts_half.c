#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: pointer to the string
 *
 * Description: This function prints the second half of the string
 *              pointed to by str, followed by a new line. If the
 *              length is odd, it prints the last (length + 1) / 2
 *              characters.
 */
void puts_half(char *str)
{
	int i = 0, len, start;

	/* حساب طول السلسلة */
	while (str[i] != '\0')
		i++;
	len = i;

	/* تحديد نقطة البداية للنصف الثاني */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* طباعة النصف الثاني */
	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
