#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int n;
int a[10005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // sort(a + 1, a + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        int mn = 0x3fffffff;
        for (int j = i; j <= n; j++)
        {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            if (mx - mn == j - i)
                cnt++;
        }
    }
    cout << cnt;
}
