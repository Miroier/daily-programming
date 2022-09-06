#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], tmp[N];
long long cnt;

void merge_sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++], cnt += mid - i + 1; //计算逆序对
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(0, n - 1);
    cout << cnt;
}
