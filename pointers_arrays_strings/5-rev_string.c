#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Description: This function reverses the string pointed to by s
 *              in place, swapping characters from start to end.
 */
void rev_string(char *s)
{
	int i = 0, j;
	char temp;

	/* حساب طول السلسلة */
	while (s[i] != '\0')
		i++;

	j = i - 1; /* آخر حرف */
	i = 0;     /* أول حرف */

	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
