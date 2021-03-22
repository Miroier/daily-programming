#include "iostream"
#include "queue"
using namespace std;
int n, m;
const int N = 10005;
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
int cnt[N];
bool st[N]; //表示当前节点是否在队列当中，防止队列中存重复的点
bool spfa()
{
    //这里没有置dis为INF，因为不要求最短路径长度
    queue<int> q;
    // 将所有点都放入队列，因为题目没有说是从某个点开始的负环
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }
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
                cnt[j] = cnt[tmp] + 1;
                if (cnt[j] >= n) //有负环
                    return false;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}
void work()
{
    if (!spfa())
        cout << "Yes";
    else
        cout << "No";
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
