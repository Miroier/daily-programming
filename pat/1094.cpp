#include "iostream"
#include "vector"
using namespace std;
int n, m;
vector<int> v[100];
int cnt[105];
void inp()
{
    cin >> n >> m;
    int a, k, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> k;
        while (k--)
        {
            cin >> b;
            v[a].push_back(b);
        }
    }
}
bool vis[100];
void dfs(int x, int layer)
{
    if (vis[x])
        return;
    vis[x] = true;
    cnt[layer]++;
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i], layer + 1);
}
void work()
{
    dfs(1, 1);
    int mxind = 0, mx = 0;
    for (int i = 1; i <= 100; i++)
        if (mx < cnt[i])
            mx = cnt[i], mxind = i;
    cout << mx << " " << mxind;
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
