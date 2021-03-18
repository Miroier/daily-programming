#include "iostream"
using namespace std;
typedef long long LL;
int n;
int a[100005];
int tmp[100005];
LL cnt = 0;
void mergesort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    int i = left, j = mid + 1;
    int ind = left;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            tmp[ind++] = a[i++];
        else
            tmp[ind++] = a[j++], cnt += mid - i + 1;
    }
    while (i <= mid)
        tmp[ind++] = a[i++];
    while (j <= right)
        tmp[ind++] = a[j++];
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
    cout << cnt;
}
