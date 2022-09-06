#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int a[N];

void quick_sort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    // 只用在第k小数所在区间排序
    if (k - 1 <= j)
        quick_sort(a, l, j);
    else
        quick_sort(a, j + 1, r);
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quick_sort(a, 0, n - 1);
    cout << a[k - 1];
}
