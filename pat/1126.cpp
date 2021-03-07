#include "iostream"
#include "vector"
using namespace std;
/*
    首先判断是否是联通图
    如果不是
        不是欧拉图
    如果是的话
        如果所有节点的度是偶数，那么是欧拉图
        如果有两个节点的度是奇数，其他都是偶数，那么是半欧拉图
        否则不是欧拉图
 */
vector<int> v[510];
int n, m;
bool vis[510];
int cnt = 0;
void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    cnt++;
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i]);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << v[i].size() << (i < n ? " " : "\n");
    if (cnt == n)
    {
        int even = 0;
        for (int i = 1; i <= n; i++)
            if (v[i].size() % 2 == 0)
                even++;
        if (even == n)
            cout << "Eulerian";
        else if (even == n - 2)
            cout << "Semi-Eulerian";
        else
            cout << "Non-Eulerian";
    }
    else
        cout << "Non-Eulerian";
}
