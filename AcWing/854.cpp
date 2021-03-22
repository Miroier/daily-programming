#include "iostream"
using namespace std;
const int N = 205;
const int INF = 0x3fffffff;
int n, m, k;
int d[N][N];
void inp()
{
    cin >> n >> m >> k;
    fill(d[0], d[0] + N * N, INF);
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
void work()
{
    floyd();
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << d[x][y] << endl;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
