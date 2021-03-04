#include "iostream"
#include "vector"
using namespace std;
struct road
{
    int other;
    int dis, timewei;
};
int n, m;
int st, ed;
vector<road> g[510];
void inp()
{
    cin >> n >> m;
    int v1, v2, one_way, dis, timewei;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> one_way >> dis >> timewei;
        g[v1].push_back({v2, dis, timewei});
        if (one_way == 0)
            g[v2].push_back({v1, dis, timewei});
    }
    cin >> st >> ed;
}
bool vis[510];
int dis[510];
int timewei[510];
const int INF = 0x3fffffff;
int dispre[510];
int timepre[510];
int sum[510];
void Ddis(int s)
{
    fill(dis, dis + 510, INF);
    fill(vis, vis + 510, false);
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
                    dispre[v] = u;
                    timewei[v] = timewei[u] + g[u][j].timewei;
                }
                else if (dis[v] == dis[u] + g[u][j].dis && timewei[v] > timewei[u] + g[u][j].timewei)
                {
                    dispre[v] = u;
                    timewei[v] = timewei[u] + g[u][j].timewei;
                }
            }
        }
    }
}
void Dtime(int s)
{

    fill(timewei, timewei + 510, INF);
    fill(vis, vis + 510, false);
    timewei[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, mn = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && mn > timewei[j])
                u = j, mn = timewei[j];
        if (u == -1)
            break;
        vis[u] = true;
        for (int j = 0; j < g[u].size(); j++)
        {
            int v = g[u][j].other;
            if (!vis[v])
            {
                if (timewei[v] > timewei[u] + g[u][j].timewei)
                {
                    timewei[v] = timewei[u] + g[u][j].timewei;
                    timepre[v] = u;
                    sum[v] = sum[u] + 1;
                }
                else if (timewei[v] == timewei[u] + g[u][j].timewei && sum[v] > sum[u] + 1)
                {
                    timepre[v] = u;
                    sum[v] = sum[u] + 1;
                }
            }
        }
    }
}
vector<int> pathdis, pathtime;
int value = INF;
void dfsdis(int x)
{
    if (x == st)
    {
        pathdis.push_back(x);
        return;
    }
    dfsdis(dispre[x]);
    pathdis.push_back(x);
}
void dfstime(int x)
{
    if (x == st)
    {
        pathtime.push_back(x);
        return;
    }
    dfstime(timepre[x]);
    pathtime.push_back(x);
}
void work()
{
    Ddis(st);
    dfsdis(ed);
    Dtime(st);
    dfstime(ed);
    printf("Distance = %d", dis[ed]);
    if (pathdis == pathtime)
    {
        printf("; Time = %d: ", timewei[ed]);
    }
    else
    {
        cout << ": ";
        for (int i = 0; i < pathdis.size(); i++)
        {
            if (i != 0)
                cout << " -> ";
            cout << pathdis[i];
        }
        printf("\nTime = %d: ", timewei[ed]);
    }
    for (int i = 0; i < pathtime.size(); i++)
    {
        if (i != 0)
            cout << " -> ";
        cout << pathtime[i];
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
