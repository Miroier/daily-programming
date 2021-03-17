#include "iostream"
using namespace std;
int dp[105][105];
int t, r, c;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> dp[i][j];
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                dp[i][j] = dp[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        int res = 0;
        for (int i = 1; i <= c; i++)
            res = max(res, dp[r][i]);
        cout << res << endl;
    }
}
