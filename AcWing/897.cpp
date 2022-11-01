#include <iostream>
using namespace std;
const int N = 1005;
int n, m;
string a, b;
int f[N][N];
int main()
{
    cin >> n >> m;
    cin >> a >> b;
    a = " " + a, b = " " + b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m];
}
