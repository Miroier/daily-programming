#include "iostream"
using namespace std;
const int N = 100005;
int a[N], diff[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        diff[i] = a[i] - a[i - 1];
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }
    fill(a, a + N, 0);
    for (int i = 1; i <= n; i++)
        a[i] = diff[i], a[i] += a[i - 1], cout << a[i] << " ";
}
