/*
    二分边的最大长度mid，只使用边长小于mid的边，在这个基础上判断是否有从1到n的路径条数小于n（公司数量），可以用最短路算法，由于每条边的权重都是1，所以也可以用bfs
    00..011..11，二分得到最左边的1，就是答案
*/
#include "cstring"
#include "iostream"
using namespace std;
const int N = 100005, M = 400005;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dis[N];
int q[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int bfs(int mid)
{
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    int hh = 0, tt = 0;
    q[0] = 1;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            if (w[i] > mid) //如果边长大于mid，不使用
                continue;
            int j = e[i];
            if (dis[j] > dis[t] + 1)
            {
                dis[j] = dis[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return dis[n];
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int left = 0, right = 1e6;
    while (left < right)
    {
        int mid = left + right >> 1;
        if (bfs(mid) <= n)
            right = mid;
        else
            left = mid + 1;
    }
    cout << left;
}
