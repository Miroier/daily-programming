/* 格子中输出 */

#include <stdio.h>
#include <string.h>

void StringInGrid(int width, int height, const char *s)
{
    int i, k;
    char buf[1000];
    strcpy(buf, s);
    if (strlen(s) > width - 2)
        buf[width - 2] = 0;
    //printf("%d:",(int)strlen(buf));

    printf("+");
    for (i = 0; i < width - 2; i++)
        printf("-");
    printf("+\n");

    for (k = 1; k < (height - 1) / 2; k++)
    {
        printf("|");
        for (i = 0; i < width - 2; i++)
            printf(".");
        printf("|\n");
    }

    printf("|");
    //printf("%d:\n",sz);
    printf("%*s%s%*s", (width - 2 - strlen(buf)) / 2, "", buf, (width - 2 - strlen(buf)) - (width - 2 - strlen(buf)) / 2, ""); //填空

    printf("|\n");

    for (k = (height - 1) / 2 + 1; k < height - 1; k++)
    {
        printf("|");
        for (i = 0; i < width - 2; i++)
            printf(".");
        printf("|\n");
    }

    printf("+");
    for (i = 0; i < width - 2; i++)
        printf("-");
    printf("+\n");
}

int main()
{
    StringInGrid(10, 4, "abcd123");
    return 0;
}
