#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int Cmax, n, Sp, m;
struct road
{
    int other;
    int weight;
};
vector<road> r[510];
int bike[510];
void inp()
{
    cin >> Cmax >> n >> Sp >> m;
    for (int i = 1; i <= n; i++)
        cin >> bike[i], bike[i] -= Cmax / 2;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        r[a].push_back({b, c});
        r[b].push_back({a, c});
    }
}
bool vis[510];
int dis[510];
const int INF = 0x3f3f3f3f;
vector<int> pre[510];
void Dijkstra(int s)
{
    fill(dis, dis + 510, INF);
    dis[s] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1, mn = INF;
        for (int j = 0; j <= n; j++)
            if (vis[j] == false && dis[j] < mn)
                u = j, mn = dis[j];
        if (u == -1)
            break;
        vis[u] = true;
        for (int j = 0; j < r[u].size(); j++)
        {
            int v = r[u][j].other;
            if (vis[v] == false && r[u][j].weight != INF)
            {
                if (dis[u] + r[u][j].weight < dis[v])
                {
                    dis[v] = dis[u] + r[u][j].weight;
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[u] + r[u][j].weight == dis[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int tmpPath[510];
int cnt = 0;
int minNeed = INF;
int minBack = INF;
int minPath[510];
int minCnt;
void dfs(int x)
{

    tmpPath[cnt++] = x;
    if (x == 0)
    {
        int sum = 0;
        int need = 0, back = 0;
        for (int i = cnt - 1; i >= 0; i--)
        {
            sum += bike[tmpPath[i]];
            if (sum < need)
                need = sum;
        }
        need = 0 - need;
        back = sum + need;
        // for (int i = cnt - 1; i >= 0; i--) //这里只能从0出发
        // {
        //     int id = tmpPath[i];
        //     if (bike[id] > 0) //bike提前在输入时处理
        //     {
        //         back += bike[id];
        //     }
        //     else
        //     {
        //         if (back > (0 - bike[id]))
        //         {
        //             back += bike[id];
        //         }
        //         else
        //         {
        //             need += ((0 - bike[id]) - back);
        //             back = 0;
        //         }
        //     }
        // }
        // 题意没说清，用下面的只有25分，猜测在一些情况下，有可能need和back都大于0
        // for (int i = 0; i < cnt - 1; i++)
        //     printf("need:%d back=%d\n", need, back);
        // sum += bike[tmpPath[i]];
        // int need = max(0, (cnt - 1) * Cmax / 2 - sum);
        // int back = max(0, sum - (cnt - 1) * Cmax / 2);
        if (minNeed > need)
        {
            minNeed = need;
            minBack = back;
            for (int i = 0; i < cnt; i++)
                minPath[i] = tmpPath[i];
            minCnt = cnt;
        }
        else if (minNeed == need && minBack > back)
        {
            minBack = back;
            for (int i = 0; i < cnt; i++)
                minPath[i] = tmpPath[i];
            minCnt = cnt;
        }
        cnt--; //回退到连接到0的节点
        return;
    }
    for (int i = 0; i < pre[x].size(); i++)
        dfs(pre[x][i]);
    cnt--; //回退到父节点
}
void work()
{
    Dijkstra(0);
    dfs(Sp);
    cout << minNeed << " " << 0;
    for (int i = minCnt - 2; i >= 0; i--)
        printf("->%d", minPath[i]);
    cout << " " << minBack;
}
int main()
{
    inp();
    work();
}
