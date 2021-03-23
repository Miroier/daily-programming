/*
    两次dfs求树的直径
 */
#include "cstring"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 200005;
int n;
struct node
{
    int to, w, next;
} edge[N];
int h[N], idx;
void add(int a, int b, int c)
{
    edge[idx].to = b;
    edge[idx].w = c;
    edge[idx].next = h[a];
    h[a] = idx++;
}
void inp()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
}
bool vis[N];
LL mxind, mxlen;
void dfs(int x, int len)
{
    if (mxlen < len)
        mxlen = len, mxind = x;
    vis[x] = true;
    for (int i = h[x]; ~i; i = edge[i].next)
    {
        int j = edge[i].to;
        if (!vis[j])
            dfs(j, len + edge[i].w);
    }
}
void work()
{
    dfs(1, 0);
    mxlen = 0;
    memset(vis, false, sizeof vis);
    dfs(mxind, 0);
    cout << mxlen * 10 + mxlen * (mxlen + 1) / 2;
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
