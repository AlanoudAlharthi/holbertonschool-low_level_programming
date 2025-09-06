#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_int(int *a, int *b)
{
    int temp;

    temp = *a;  /* حفظ قيمة a في متغير مؤقت */
    *a = *b;    /* نقل قيمة b إلى a */
    *b = temp;  /* نقل القيمة المحفوظة في temp إلى b */
}
