#include "iostream"
#include "vector"
using namespace std;
struct road
{
    int other;
    int dis;
    int cost;
};
int n, m, s, d;
const int MAXN = 510;
vector<road> g[MAXN];
void inp()
{
    cin >> n >> m >> s >> d;
    int c1, c2, dis, cost;
    for (int i = 0; i < m; i++)
    {
        cin >> c1 >> c2 >> dis >> cost;
        g[c1].push_back({c2, dis, cost});
        g[c2].push_back({c1, dis, cost});
    }
}
const int INF = 0x7fffffff;
int dis[MAXN];
int cost[MAXN];
bool vis[MAXN];
int pre[MAXN];
void Dijkstra(int s)
{
    fill(dis, dis + MAXN, INF);
    fill(cost, cost + MAXN, INF);
    dis[s] = 0;
    cost[s] = 0;
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
                    cost[v] = cost[u] + g[u][j].cost;
                    pre[v] = u;
                }
                else if (dis[v] == dis[u] + g[u][j].dis && cost[v] > cost[u] + g[u][j].cost)
                {
                    cost[v] = cost[u] + g[u][j].cost;
                    pre[v] = u;
                }
            }
        }
    }
}

void dfs(int s, int d)
{
    if (d == s)
    {
        cout << s << " ";
        return;
    }
    dfs(s, pre[d]);
    cout << d << " ";
}
void work()
{
    Dijkstra(s);
    dfs(s, d);
    cout << dis[d] << " " << cost[d] << endl;
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
