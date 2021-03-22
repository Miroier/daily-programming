#include "cstring"
#include "iostream"
using namespace std;
struct node
{
    int x, y;
};
int n;
char g[1005][1005];
bool vis[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool dfs(node s)
{
    vis[s.x][s.y] = true;
    // 检查自己
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        int x = s.x + dx[i];
        int y = s.y + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= n)
            continue;
        flag &= (g[x][y] == '#'); //如果全部是陆地，该岛屿不会完全沉
    }
    // 检查周围的点，这里不提前返回是为了每一次dfs把岛屿的每一块vis都标成true
    for (int i = 0; i < 4; i++)
    {
        int x = s.x + dx[i];
        int y = s.y + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= n)
            continue;
        if (!vis[x][y] && g[x][y] == '#')
            flag |= dfs({x, y});
    }
    return flag;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[i][j] && g[i][j] == '#')
                if (!dfs({i, j}))
                    ans++;
    cout << ans;
}
