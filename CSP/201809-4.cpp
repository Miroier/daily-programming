/*
    求最小值，这样一定满足字典序最小
    求最小值相当于求最长路
    下面的dis相当于前缀和数组
    约束条件
    s[i + 1] >= s[i - 2] + 3 * b[i]
    s[i - 2] >= s[i + 1] - (3 * b[i] + 2)
    s[i] >= s[i - 1] + 1
 */
#include "cstring"
#include "iostream"
#include "queue"
using namespace std;
const int N = 305, M = N * 3;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dis[N];
int b[N];
queue<int> q;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool st[N];
void spfa()
{
    memset(dis, -0x3f, sizeof dis);
    dis[0] = 0;
    q.push(0);
    st[0] = true;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        st[tmp] = false;
        for (int i = h[tmp]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dis[j] < dis[tmp] + w[i])
            {
                dis[j] = dis[tmp] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 2; i <= n - 1; i++)
    {
        add(i - 2, i + 1, 3 * b[i]);
        add(i + 1, i - 2, -(b[i] * 3 + 2));
    }
    add(0, 2, 2 * b[1]), add(2, 0, -(2 * b[1] + 1));
    add(n - 2, n, 2 * b[n]), add(n, n - 2, -(2 * b[n] + 1));
    for (int i = 1; i <= n; i++)
        add(i - 1, i, 1);
    spfa();
    for (int i = 1; i <= n; i++)
        cout << dis[i] - dis[i - 1] << " ";
}
