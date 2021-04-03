/*
    状态表示
        集合：f[i,j]表示前i个总和是j
        属性：bool
    状态计算
        f[i.j]=f[i-1,j]|f[i-1,j-a[i]]
 */
#include "iostream"
using namespace std;
const int N = 105;
int n;
int a[N];
bool f[N][N * N];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d = gcd(d, a[i]);
    }
    if (d != 1)
        cout << "INF";
    else
    {
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < N * N; j++)
            {
                f[i][j] = f[i - 1][j];
                if (j >= a[i])
                    f[i][j] |= f[i][j - a[i]];
            }
        int res = 0;
        for (int i = 0; i < N * N; i++)
            if (!f[n][i])
                res++;
        cout << res;
    }
}
