#include "iostream"
using namespace std;
const int MOD = 1000000007, N = 55;

int n, m, k;
int a[N][N];
int f[N][N][13][14];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j]++; //-1~12 -> 0~13 第4维大小为14
    f[1][1][1][a[1][1]] = 1;           //取
    f[1][1][0][0] = 1;                 //不取
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            for (int u = 0; u <= k; u++)
                for (int v = 0; v <= 13; v++)
                {
                    int &val = f[i][j][u][v];
                    // 不拿
                    val = (val + f[i - 1][j][u][v]) % MOD;
                    val = (val + f[i][j - 1][u][v]) % MOD;
                    // 拿
                    if (u > 0 && v == a[i][j])
                    {
                        for (int c = 0; c < v; c++)
                        {
                            val = (val + f[i - 1][j][u - 1][c]) % MOD;
                            val = (val + f[i][j - 1][u - 1][c]) % MOD;
                        }
                    }
                }
        }
    int res = 0;
    for (int i = 0; i <= 13; i++)
        res = (res + f[n][m][k][i]) % MOD;
    cout << res;
}
