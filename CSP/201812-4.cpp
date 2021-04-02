/*
    题目相当于求最大边权最小的最小生成树
    和普通的最小生成树相比就一个区别：先把边排序
 */
#include "algorithm"
#include "iostream"
using namespace std;
const int N = 50005, M = 100005;
int n, m, root;
struct edge
{
    int u, v, w;
    bool friend operator<(edge a, edge b)
    {
        return a.w < b.w;
    }
};
edge g[M];
int dad[N];
int anc(int x)
{
    if (dad[x] != x)
        return dad[x] = anc(dad[x]);
    return x;
}
void uni(int x, int y)
{
    x = anc(x);
    y = anc(y);
    if (x != y)
    {
        dad[x] = y;
    }
}
bool find(int x, int y)
{
    return anc(x) == anc(y);
}
int main()
{
    cin >> n >> m >> root;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[i] = {u, v, w};
    }
    sort(g, g + m);
    for (int i = 1; i <= n; i++)
        dad[i] = i;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; cnt < n - 1; i++)
    {
        int u, v;
        u = g[i].u, v = g[i].v;
        if (!find(u, v))
        {
            uni(u, v);
            cnt++;
            ans = g[i].w;
        }
    }
    cout << ans;
}
