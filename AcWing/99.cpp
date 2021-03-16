#include "iostream"
using namespace std;
int n, r;
int g[5005][5005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        g[x + 1][y + 1] += v;
    }
    for (int i = 1; i <= 5000; i++)
        for (int j = 1; j <= 5000; j++)
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    int mx = 0;
    for (int i = r; i <= 5000; i++)
        for (int j = r; j <= 5000; j++)
        {
            int tmp = g[i][j] - g[i - r][j] - g[i][j - r] + g[i - r][j - r];
            if (mx < tmp)
                mx = tmp;
        }
    cout << mx;
}
