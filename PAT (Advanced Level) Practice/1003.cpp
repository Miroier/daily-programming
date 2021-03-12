#include "iostream"
using namespace std;
const int N = 510;
const int inf = 0x3fffffff;
int n, m, c1, c2;
int g[N][N], node[N];
int dis[N];
int num[N]; //number of shortest paths
int cnt[N]; //maximum amount of rescue teams
bool vis[N];
void inp()
{

    fill(g[0], g[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        cin >> node[i];
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }
}
int main()
{
    inp();
    dis[c1] = 0;
    num[c1] = 1;
    cnt[c1] = node[c1];
    for (int i = 0; i < n; i++)
    {
        int u = -1, mn = inf;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < mn)
            {
                u = j;
                mn = dis[j];
            }
        }
        if (u == -1)
            break;
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && g[u][v] != inf)
            {
                if (dis[u] + g[u][v] < dis[v])
                {
                    dis[v] = dis[u] + g[u][v];
                    num[v] = num[u];
                    cnt[v] = cnt[u] + node[v];
                }
                else if (dis[u] + g[u][v] == dis[v])
                {
                    num[v] += num[u];
                    if (cnt[v] < cnt[u] + node[v])
                        cnt[v] = cnt[u] + node[v];
                }
            }
        }
    }
    cout << num[c2] << ' ' << cnt[c2];
}
