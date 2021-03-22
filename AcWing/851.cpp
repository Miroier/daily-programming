#include "iostream"
#include "queue"
using namespace std;
int n, m;
const int N = 100005;
const int INF = 0x3fffffff;
struct edge
{
    int to, w, next;
} edge[N];
int h[N], idx;
void inp()
{
    cin >> n >> m;
    fill(h, h + N, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge[idx].to = y, edge[idx].w = z;
        edge[idx].next = h[x];
        h[x] = idx++;
    }
}
int dis[N];
bool st[N]; //表示当前节点是否在队列当中，防止队列中存重复的点
void spfa(int s)
{
    fill(dis, dis + N, INF);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    st[s] = true;
    while (q.size())
    {
        int tmp = q.front();
        q.pop();
        st[tmp] = false;
        for (int i = h[tmp]; ~i; i = edge[i].next)
        {
            int j = edge[i].to;
            if (dis[j] > dis[tmp] + edge[i].w)
            {
                dis[j] = dis[tmp] + edge[i].w;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}
void work()
{
    spfa(1);
    if (dis[n] == INF)
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
