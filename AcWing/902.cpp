#include <iostream>
using namespace std;
const int N = 1005;
int n, m;
string a, b;
int f[N][N];
int main()
{
    cin >> n >> a >> m >> b;
    a = " " + a;
    b = " " + b;
    //初始化
    for (int i = 1; i <= m; i++)
        f[0][i] = i; // a[0,0]变成b[1,i]，需要增加i次。
    for (int i = 1; i <= n; i++)
        f[i][0] = i; // a[1,i]变成b[0,0]，需要删除i次。

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m];
}
