#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *           containing a copy of the string given as a parameter
 * @str: the string to duplicate
 *
 * Return: pointer to duplicated string, or NULL if str = NULL or if malloc fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* نحسب طول النص */
	while (str[len] != '\0')
		len++;

	/* نحجز ذاكرة بطول النص + 1 (عشان \0) */
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	/* ننسخ النص */
	for (i = 0; i < len; i++)
		dup[i] = str[i];

	dup[len] = '\0'; /* نضيف null terminator */

	return (dup);
}
