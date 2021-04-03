/*
    题意：找到树的一个连通块使得这个连通块节点的和最大
    f[u]：以u为根节点的子树中包含u点的所有连通块的权值最大值
 */
#include "cstring"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 100005, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n;
LL f[N], a[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
LL dp(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        f[u] += max(dp(v, u), 0ll);
    }
    return f[u] = f[u] + a[u];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dp(1, 0);
    LL ans = f[1];
    for (int i = 2; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
}
