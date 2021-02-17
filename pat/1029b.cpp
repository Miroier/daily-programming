#include "algorithm"
#include "iostream"
using namespace std;
int n, m;
int a[200010], b[200010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0, j = 0;
    int cnt = 0;
    int target = (n + m + 1) >> 1;
    int ans;
    while (i < n && j < m)
    {
        ans = (a[i] <= b[j] ? a[i++] : b[j++]);
        if (++cnt == target)
            break;
    }
    while (i < n && cnt < target)
        ans = a[i++], ++cnt;
    while (j < m && cnt < target)
        ans = b[j++], ++cnt;
    cout << ans << endl;
}
