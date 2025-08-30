#include "main.h"

/* دالة مساعدة لطباعة الأعداد باستخدام _putchar */
void print_number(int n)
{
    if (n < 0)
    {
        _putchar('-');   /* طباعة علامة السالب */
        n = -n;          /* تحويل الرقم للموجب */
    }
    if (n / 10)
        print_number(n / 10);  /* طباعة جميع الأرقام إلا الأخيرة */
    _putchar((n % 10) + '0'); /* طباعة الرقم الأخير */
}

/* الدالة الرئيسية التي تطبع الأعداد من n إلى 98 */
void print_to_98(int n)
{
    int i;

    if (n <= 98)
    {
        for (i = n; i < 98; i++)
        {
            print_number(i);
            _putchar(',');
            _putchar(' ');
        }
    }
    else
    {
        for (i = n; i > 98; i--)
        {
            print_number(i);
            _putchar(',');
            _putchar(' ');
        }
    }

    print_number(98);  /* طباعة الرقم الأخير */
    _putchar('\n');    /* سطر جديد */
}
