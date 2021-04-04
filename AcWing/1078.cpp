/*
    先通过树形dp求出每个点往下走的最大长度和次大长度，并且更新整棵树的最大路径ans
    枚举每一个结点i，设该点的最大长度是d1[i]，次大长度是d2[i]，若d1[i] + d2[i] == ans，表示最大路径是从该点得出的，通过dfs2找到最大长度的路径，dfs3找到次大长度的路径，并对路径的点进行标记
 */
#include "algorithm"
#include "cstring"
#include "iostream"
#include "set"
using namespace std;
const int N = 200005, M = N * 2;
int n;
int f[N];
int h[N], e[M], ne[M], idx;
int d1[N], d2[N]; //最大值和次大值
int ans = 0;
set<int> st;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//从u点向下走的最大长度和最小长度
void dfs1(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v != fa)
        {
            dfs1(v, u);
            int distance = d1[v] + 1;
            if (distance > d1[u])
            {
                d2[u] = d1[u];
                d1[u] = distance;
            }
            else if (distance > d2[u])
            {
                d2[u] = distance;
            }
        }
        ans = max(ans, d1[u] + d2[u]);
    }
}
//最大长度路径
void dfs2(int u)
{
    st.insert(u);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (d1[u] == d1[v] + 1)
            dfs2(v);
    }
}
//次大长度路径
void dfs3(int u)
{
    st.insert(u);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (d2[u] == d1[v] + 1)
            dfs2(v);
    }
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs1(0, -1);
    for (int i = 0; i < n; i++)
    {
        if (d1[i] + d2[i] == ans)
        {
            dfs2(i);
            dfs3(i);
        }
    }
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        cout << *it << endl;
}
