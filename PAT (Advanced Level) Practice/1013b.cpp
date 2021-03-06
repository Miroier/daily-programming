#include "iostream"
#include "vector"
using namespace std;
int n, m, k;
bool a[1010][1010];
bool vis[1010];
void inp()
{
    cin >> n >> m >> k;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}
void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    for (int i = 1; i <= n; i++)
        if (a[x][i])
            dfs(i);
}
void work()
{
    int x;
    for (int i = 0; i < k; i++)
    {
        fill(vis, vis + 1010, false);
        cin >> x;
        int cnt = 0;
        vis[x] = true;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j])
                continue;
            dfs(j);
            cnt++;
        }
        cout << cnt - 1 << endl;
    }
}
int main()
{
    inp();
    work();
}
