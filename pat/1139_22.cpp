#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m;
int dad[20010];
/*
    用数字无法判断0的性别
    dfs 最后一个点超时
 */
struct peo
{
    int val;
    bool gender; //1:boy 0:girl
};
vector<peo> v[20010];
const int offset = 10000;
int anc(int x)
{
    if (dad[x])
        return dad[x] = anc(dad[x]);
    return x;
}
void uni(int x, int y)
{
    x = anc(x);
    y = anc(y);
    if (x != y)
        dad[x] = y;
}
bool find(int x, int y)
{
    return anc(x) == anc(y);
}
void inp()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x + offset].push_back({y + offset, y > 0});
        v[y + offset].push_back({x + offset, x > 0});
        uni(x + offset, y + offset);
    }
}
bool vis[20010];
vector<peo> tmp;
vector<pair<int, int>> ans;
void dfs(int x, int y)
{
    if (x == y)
    {
        tmp.push_back({x, x > offset});
        if (tmp.size() == 4 && tmp[0].gender == tmp[1].gender && tmp[2].gender == tmp[3].gender)
        {
            pair<int, int> t;
            t.first = abs(tmp[1].val - offset);
            t.second = abs(tmp[2].val - offset);
            ans.push_back(t);
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back({x, x > offset});
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i++)
        if (!vis[v[x][i].val] && find(x, v[x][i].val))
            dfs(v[x][i].val, y);
    tmp.pop_back();
    vis[x] = 0;
}
void work()
{
    int k;
    cin >> k;
    int x, y;
    while (k--)
    {
        cin >> x >> y;
        fill(vis, vis + 20010, false);
        ans.clear();
        dfs(x + offset, y + offset);
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            printf("%04d %04d\n", ans[i].first, ans[i].second);
    }
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
