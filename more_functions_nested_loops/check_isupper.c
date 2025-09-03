#include <stdio.h>
#include "main.h"
int main(void)
{
    int c;
    for (c = 32; c <= 126; c++)
    {
        printf("%c: %d\n", c, _isupper(c));
    }
    return (0);
}
