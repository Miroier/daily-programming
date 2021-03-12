#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m, k, ds;
struct road
{
    int other;
    double dis;
};
vector<road> g[1020];
void inp()
{
    cin >> n >> m >> k >> ds;
    string x, y;
    int ix, iy;
    double dis;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> dis;
        if (x[0] == 'G')
            ix = stoi(x.substr(1)) + n;
        else
            ix = stoi(x);
        if (y[0] == 'G')
            iy = stoi(y.substr(1)) + n;
        else
            iy = stoi(y);
        g[ix].push_back({iy, dis});
        g[iy].push_back({ix, dis});
    }
}
bool vis[1020];
double dis[1020];
const int INF = 0x3fffffff;
void Dijkstra(int s)
{
    fill(vis, vis + 1020, false);
    fill(dis, dis + 1020, INF);
    dis[s] = 0;
    for (int i = 0; i < n + m; i++)
    {
        int u = -1;
        double mn = INF;
        for (int j = 1; j <= n + m; j++)
            if (!vis[j] && mn > dis[j])
                u = j, mn = dis[j];
        if (u == -1)
            break;
        vis[u] = true;
        for (int j = 0; j < g[u].size(); j++)
        {
            int v = g[u][j].other;
            if (!vis[v] && dis[v] > dis[u] + g[u][j].dis)
            {
                dis[v] = dis[u] + g[u][j].dis;
            }
        }
    }
}
void work()
{
    double mxmin = 0;
    double average = INF;
    int index = -1;
    for (int i = 1; i <= m; i++)
    {
        double aver = 0;
        double mn = INF;
        bool flag = false;
        Dijkstra(n + i);
        for (int j = 1; j <= n; j++)
        {
            aver += dis[j];
            if (mn > dis[j])
                mn = dis[j];
            if (dis[j] > ds)
                flag = true;
        }
        if (flag)
            continue;
        aver /= n;
        if (mxmin < mn)
        {
            mxmin = mn;
            average = aver;
            index = i;
        }
        else if (mxmin == mn && average > aver)
        {
            average = aver;
            index = i;
        }
    }
    if (index != -1)
        printf("G%d\n%.1lf %.1lf", index, mxmin, average + 0.005); //不加0.005的话能过，但是在本地输出3.2
    else
        cout << "No Solution";
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
