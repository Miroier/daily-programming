#include "iostream"
#include "map"
#include "vector"
using namespace std;
const int INF = 0x3fffffff;
int localhap[210];
int n, k;
map<string, int> s2i;
map<int, string> i2s;
int g[210][210];
void inp()
{
    fill(g[0], g[0] + 210 * 210, INF);
    cin >> n >> k;
    string city;
    cin >> city;
    s2i[city] = 0;
    i2s[0] = city;
    int happy;
    for (int i = 1; i < n; i++)
    {
        cin >> city >> happy;
        s2i[city] = i;
        i2s[i] = city;
        localhap[i] = happy;
    }
    string city2;
    int w;
    for (int i = 0; i < k; i++)
    {
        cin >> city >> city2 >> w;
        g[s2i[city]][s2i[city2]] = g[s2i[city2]][s2i[city]] = w;
    }
}
int dis[210];
bool vis[210];
vector<int> pre[210];
void Dijkstra(int s)
{
    fill(dis, dis + 210, INF);
    fill(vis, vis + 210, false);
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, mn = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && dis[j] < mn)
                u = j, mn = dis[j];
        if (u == -1)
            break;
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && g[u][v] != INF)
            {
                if (dis[v] > dis[u] + g[u][v])
                {
                    dis[v] = dis[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[v] == dis[u] + g[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> path;
vector<int> tmppath;
int maxhappy;
int averhappy;
int cnt;
void dfs(int x)
{
    if (x == 0)
    {
        cnt++;
        tmppath.push_back(x);
        int happy = 0;
        for (int i = tmppath.size() - 1; i >= 0; i--)
        {
            int id = tmppath[i];
            happy += localhap[id];
        }
        if (happy > maxhappy)
        {
            maxhappy = happy;
            path = tmppath;
            averhappy = happy / (tmppath.size() - 1);
        }
        else if (happy == maxhappy && happy / (tmppath.size() - 1) > averhappy)
        {
            averhappy = happy / (tmppath.size() - 1);
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(x);
    for (int i = 0; i < pre[x].size(); i++)
        dfs(pre[x][i]);
    tmppath.pop_back();
}
void work()
{
    Dijkstra(0);
    dfs(s2i["ROM"]);
    cout << cnt << " " << dis[s2i["ROM"]] << " " << maxhappy << " " << averhappy << endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << i2s[path[i]];
        if (i > 0)
            cout << "->";
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
