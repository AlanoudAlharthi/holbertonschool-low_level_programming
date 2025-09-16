#include <stdlib.h> /* for malloc */
#include "main.h"

/**
 * create_array - creates an array of chars, and initializes it with a char
 * @size: the size of the array
 * @c: the char to fill the array with
 *
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
    char *arr;
    unsigned int i;

    /* لو الحجم صفر نرجع NULL */
    if (size == 0)
        return (NULL);

    /* نحجز ذاكرة بالحجم المطلوب */
    arr = malloc(sizeof(char) * size);
    if (arr == NULL) /* malloc فشل */
        return (NULL);

    /* نملأ المصفوفة بالحرف c */
    for (i = 0; i < size; i++)
        arr[i] = c;

    return (arr);
}
