#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n;
vector<int> g[10010];
void inp()
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
int ans[10010];
bool vis[10010];
void dfs(int x, int depth)
{
    if (vis[x])
        return;
    vis[x] = true;
    ans[x] = max(ans[x], depth);
    for (int i = 0; i < g[x].size(); i++)
        dfs(g[x][i], depth + 1);
}
void work()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i, 0);
        cnt++;
    }
    if (cnt > 1)
        printf("Error: %d components", cnt);
    else
    {
        for (int i = 1; i <= n; i++)
        {
            fill(vis, vis + 10010, false);
            dfs(i, 0);
        }
        int mx = -1;
        for (int i = 1; i <= n; i++)
            mx = max(mx, ans[i]);
        for (int i = 1; i <= n; i++)
            if (mx == ans[i])
                cout << i << endl;
    }
}
int main()
{
    inp();
    work();
}
