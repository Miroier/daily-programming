#include "iostream"
using namespace std;
int n;
int a[100005];
int tmp[100005];
void mergesort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    int i = left, j = mid + 1;
    int cnt = left;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
            tmp[cnt++] = a[i++];
        else
            tmp[cnt++] = a[j++];
    }
    while (i <= mid)
        tmp[cnt++] = a[i++];
    while (j <= right)
        tmp[cnt++] = a[j++];
    for (int i = left; i <= right; i++)
        a[i] = tmp[i];
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    mergesort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
