/* 消除尾一 */
#include <stdio.h>

void f(int x)
{
    int i;
    for (i = 0; i < 32; i++)
        printf("%d", (x >> (31 - i)) & 1);
    printf("....");

    x = x & (x + 1);

    for (i = 0; i < 32; i++)
        printf("%d", (x >> (31 - i)) & 1);
    printf("\n");
}

int main()
{
    f(128 + 64 + 2);
    f(128 + 64 + 15);
    f(128 + 64 + 1);

    return 0;
}
