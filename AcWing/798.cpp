#include <iostream>
using namespace std;
const int N = 1005;
int a[N][N], b[N][N];
int n, m, q;
int x1, y1, x2, y2, c;
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        b[x1][y1] += c;
        b[x1][y2 + 1] -= c;
        b[x2 + 1][y1] -= c;
        b[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << (j < m ? " " : "\n");
}
