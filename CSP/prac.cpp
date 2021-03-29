/*
    x节点的父亲记为fa[0][x]，根节点的父亲记作自己，即fa[0][1]=1
    设fa[i][x]表示x节点向上的第2^i个父亲，可以得到一个表达式fa[i][x]=fa[i-1][fa[i-1][x]]，即x向上跳两次2^(i-1)
 */
const int M = 100005;
int n; //节点数量
int h[M], e[M], ne[M];
int fa[17][M], d[M];
void dfs(int x)
{
    for (int i = h[x]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa[0][x])
            continue;
        d[v] = d[x] + 1;
        fa[0][v] = x;
        dfs(v);
    }
}
void build()
{
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= n; i++)
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
}
int query(int u, int v)
{
    if (d[u] > d[v])
        swap(u, v);
    int tmp = d[v] - d[u];
    for (int i = 17; i >= 0; i--)
        if (tmp >= (1 << i))
            v = fa[i][v], tmp -= (1 << i);
    for (int i = 17; i >= 0; i--)
    {
        if (fa[i][v] != fa[i][u])
            u = fa[i][u], v = fa[i][v];
    }
    return fa[0][v];
}
