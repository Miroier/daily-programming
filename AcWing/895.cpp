#include "iostream"
using namespace std;
int n;
int a[1005];
int dp[1005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    fill(dp, dp + 1005, 1);
    // dp[0] = 0x3fffffff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    cout << res << endl;
}
