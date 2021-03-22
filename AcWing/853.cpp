#include "cstring"
#include "iostream"
#include "vector"
using namespace std;
const int N = 505;
const int INF = 0x3fffffff;
int n, m, k;
struct road
{
    int v;
    int dis;
};
vector<road> g[N];
int dis[N], backup[N];
void inp()
{

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }
}
bool Bellman(int s)
{
    fill(dis, dis + N, INF);
    dis[s] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dis, sizeof dis); //做个备份，避免出现串联
        for (int u = 1; u <= n; u++)
            for (int j = 0; j < g[u].size(); j++)
            {
                int v = g[u][j].v;
                if (dis[v] > backup[u] + g[u][j].dis)
                    dis[v] = backup[u] + g[u][j].dis;
            }
    }
}
void work()
{
    Bellman(1);
    if (dis[n] > INF / 2) //因为有负权边，而bellman算法会遍历每条边，因可能到不了点n，但是点n会被相邻的点(INF)更新成(INF-x)
        cout << "impossible";
    else
        cout << dis[n];
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
