/* 快速排序 */
#include <stdio.h>

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int a[], int p, int r)
{
    int i = p;
    int j = r + 1;
    int x = a[p];
    while (1)
    {
        while (i < r && a[++i] < x)
            ;
        while (a[--j] > x)
            ;
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, p, j);
    return j;
}

void quicksort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

int main()
{
    int i;
    int a[] = {50, 49, 48, 48, 47, 46, 1, 3, 5, 2, 4, 6, 30, 30, 30, 30};
    int N = 16;

    quicksort(a, 0, N - 1);

    for (i = 0; i < N; i++)
        printf("%d.", a[i]);
    printf("\n");

    return 0;
}
