#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
vector<pair<int, int>> v[110];
int weight[110];
int n, m, s;
// 放个pair用来绑定id和weight进行排序，深搜时可以不用（因为有weight[110]了）
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}
void inp()
{
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    int d, k;
    for (int i = 0; i < m; i++)
    {
        cin >> d >> k;
        int x;
        while (k--)
        {
            cin >> x;
            v[d].push_back(make_pair(x, weight[x]));
        }
        sort(v[d].begin(), v[d].end(), cmp);
    }
}
bool vis[110];
int ans[110];
int cnt = 0;
void dfs(int x, int sum)
{
    if (vis[x])
        return;
    vis[x] = true;
    sum += weight[x];
    ans[cnt++] = x;
    if (sum == s && !v[x].size())
    {
        for (int i = 0; i < cnt; i++)
            cout << weight[ans[i]] << (i < cnt - 1 ? " " : "\n");
        cnt--;
        sum -= weight[x];
        return;
    }
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i].first, sum);
    cnt--;
    sum -= weight[x];
}
void work()
{
    dfs(0, 0);
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
