#include <iostream>
using namespace std;
const int N = 305, INF = 1e9;
int n;
int a[N], sum[N];
int f[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    fill(f[0], f[0] + N * N, INF);
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j - 1; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
        }
    cout << f[1][n];
}
