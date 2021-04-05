/*
    dis[i,j]：从1走到点i时，最后一条小路的长度是j的前提下，最短距离是多少
    j<=1000，因为结果的最大值不超过1e6，可以把每个点拆成1000个点
 */
#include "cstring"
#include "iostream"
#include "queue"
#include "vector"
using namespace std;
const int N = 505, M = 200005;
const int INF = 1e6; //最大值不超过1e6
int n, m;
struct road
{
    bool type;
    int v;
    int dis;
};
vector<road> g[N];
int dis[N][1005];
bool st[N][1005];
struct node
{
    int x, y, dis; //x:节点编号，y:最后一条小路长度
    bool operator<(const node &a) const
    {
        return dis > a.dis; //堆
    }
};
void Dijkstra()
{
    priority_queue<node> heap;
    memset(dis, 0x3f, sizeof dis);
    heap.push({1, 0, 0});
    dis[1][0] = 0;
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        if (st[t.x][t.y]) //dijkstra每个点只更新一次
            continue;
        st[t.x][t.y] = true;
        for (int i = 0; i < g[t.x].size(); i++)
        {
            int v = g[t.x][i].v;
            int y = t.y;
            if (g[t.x][i].type)
            {
                y += g[t.x][i].dis;
                if (y <= 1000)
                {
                    if (dis[v][y] > t.dis - t.y * t.y + y * y)
                    {
                        dis[v][y] = t.dis - t.y * t.y + y * y;
                        if (dis[v][y] <= INF)
                            heap.push({v, y, dis[v][y]});
                    }
                }
            }
            else
            {
                if (dis[v][0] > t.dis + g[t.x][i].dis)
                {
                    dis[v][0] = t.dis + g[t.x][i].dis;
                    if (dis[v][0] <= INF)
                        heap.push({v, 0, dis[v][0]});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        g[a].push_back({t, b, c});
        g[b].push_back({t, a, c});
    }
    Dijkstra();
    int ans = INF;
    for (int i = 0; i <= 1000; i++)
        ans = min(ans, dis[n][i]);
    cout << ans;
}
