/*
    dp[i,j]表示总和是i，分成j个数
    划分成两个部分，一部分：最小值是0 表达式是dp[i,j-1]
                    另一部分：最小值不是0 让所有值减一 表达式是dp[i-j,j]
 */
#include "iostream"
using namespace std;
int t, m, n;
int f[15][15];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        fill(f[0], f[0] + 15 * 15, 0);
        f[0][0] = 1;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = f[i][j - 1];
                if (i >= j)
                    f[i][j] += f[i - j][j];
            }
        cout << f[m][n] << endl;
    }
}
