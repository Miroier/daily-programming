#include <iostream>
using namespace std;
const int N = 1005;
int n, m;
string a, b;
int f[N][N];
int main()
{
    cin >> n >> a;
    cin >> m >> b;
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= n; i++)
        f[i][0] = i;
    for (int i = 1; i <= m; i++)
        f[0][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m];
}
