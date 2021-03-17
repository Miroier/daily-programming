#include "iostream"
using namespace std;
const int MOD = 100000007;
int dp[1005][1005];
int getmod(int x, int y)
{
    return (x % y + y) % y;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    dp[0][0] = 1; //一个数都不取，余数是0
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = (dp[i - 1][getmod(j - (n - i) * a, n)] + dp[i - 1][getmod(j + (n - i) * b, n)]) % MOD;
        }
    cout << dp[n - 1][getmod(s, n)];
}
