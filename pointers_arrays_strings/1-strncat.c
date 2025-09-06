#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of bytes to use from src
 *
 * Return: pointer to dest
 *
 * Description: Appends the string pointed to by src to the end
 *              of the string pointed to by dest, using at most n
 *              bytes from src. Overwrites the terminating null
 *              byte at the end of dest and adds a terminating
 *              null byte.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	/* العثور على نهاية dest */
	while (dest[i] != '\0')
		i++;

	/* نسخ محتوى src حتى n حرف */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0'; /* إضافة null byte في النهاية */

	return (dest);
}
