#include <iostream>
using namespace std;
const int N = 1005, MOD = 1e9 + 7;
int n;
int f[N][N];
int main()
{
    cin >> n;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (f[n][i] + ans) % MOD;
    cout << ans;
}
