#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: pointer to dest
 *
 * Description: Appends the string pointed to by src to the end
 *              of the string pointed to by dest, overwriting the
 *              terminating null byte at the end of dest, and then
 *              adds a terminating null byte.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	/* العثور على نهاية dest */
	while (dest[i] != '\0')
		i++;

	/* نسخ محتوى src بعد نهاية dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0'; /* إضافة null byte في النهاية */

	return (dest);
}
