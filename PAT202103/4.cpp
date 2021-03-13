#include "iostream"
#include "vector"
struct road
{
    int other;
    int dis;
};
using namespace std;
typedef long long LL;
int n, m;
vector<road> g[205];
void inp()
{
    cin >> n >> m;
    n++;
    int x, y, dis;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> dis;
        g[x].push_back({y, dis});
        g[y].push_back({x, dis});
    }
}
const int INF = 0x3fffffff;
vector<vector<int>> resdis;
vector<int> dis;
bool vis[205];
void Dijkstra(int s)
{
    fill(vis, vis + 205, false);
    fill(dis.begin(), dis.end(), INF);
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, mn = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && mn > dis[j])
                u = j, mn = dis[j];
        if (u == -1)
            break;
        vis[u] = true;
        for (int j = 0; j < g[u].size(); j++)
        {
            int v = g[u][j].other;
            if (!vis[v])
            {
                if (dis[v] > dis[u] + g[u][j].dis)
                {
                    dis[v] = dis[u] + g[u][j].dis;
                }
            }
        }
    }
}
void work()
{
    resdis.resize(n, vector<int>(n));
    dis.resize(n);
    for (int i = 0; i < n; i++)
    {
        Dijkstra(i);
        resdis[i] = dis;
    }
    int sum = 0;
    fill(vis, vis + 205, false);
    vector<int> ans;
    int st = 0;
    while (1)
    {
        ans.push_back(st);
        vis[st] = true;
        int mnind = n, mndis = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (mndis > resdis[st][i])
                {
                    mndis = resdis[st][i];
                    mnind = i;
                }
                else if (mndis == resdis[st][i] && mnind > i)
                {
                    mnind = i;
                }
            }
        }
        if (mnind == n || mndis == INF)
            break;
        // cout << st << " " << mnind << " " << mndis << endl;
        st = mnind;
        sum += mndis;
    }
    if (ans.size() == n)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
        cout << sum;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
        vector<int> tmp;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                tmp.push_back(i);
        for (int i = 0; i < tmp.size(); i++)
            cout << tmp[i] << (i < tmp.size() - 1 ? " " : "\n");
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
