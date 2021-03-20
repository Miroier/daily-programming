#include "algorithm"
#include "cstring"
#include "iostream"
/*
    先预处理出d[i,j]表示从i出发走完所有包含j的点的最短距离
    想象一个二维01矩阵，表示是否满足d[i,j]<=dis，这个dis是将来要二分的距离
        0 1 2 ... k-1
    1
    2
    .
    n
    从n行里选m行,使得每一列都至少有一个1，表示所有食材都能送到
 */
using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 105, M = 10, S = 1 << M;

int n, m, k;
int need[N][M];
struct node
{
    int to;
    int w;
    int next;
} Edge[N];
int h[N], idx; //链式前向星
int d[N][M];
int f[S], state[N];
void add(int a, int b, int c)
{
    Edge[idx].to = b;
    Edge[idx].w = c;
    Edge[idx].next = h[a];
    h[a] = idx++;
}
void inp()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            cin >> need[i][j];
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
}
bool vis[N];
PII dfs(int u, int fa, int v)
{
    PII res(0, -1);
    if (need[u][v])
        res.y = 0;
    vis[u] = true;
    for (int i = h[u]; ~i; i = Edge[i].next)
    {
        int j = Edge[i].to;
        if (!vis[j])
        {
            auto t = dfs(j, u, v);
            if (t.y != -1) //如果这个酒店对该食材有要求
            {
                res.x += t.x + Edge[i].w * 2;
                res.y = max(res.y, t.y + Edge[i].w);
            }
        }
    }
    return res;
}
bool check(int mid)
{
    memset(state, 0, sizeof state);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            if (d[i][j] <= mid)
                state[i] |= 1 << j;  //state[i]表示哪些食材可以从酒店i出发
    memset(f, 0x3f, sizeof f);       // f[i]表示对于
    f[0] = 0;                        //一行也没有选时个数是0
    for (int i = 0; i < 1 << k; i++) //枚举所有行的组合
        for (int j = 1; j <= n; j++) //对于每个行
                                     //i | state[j]表示
            f[i | state[j]] = min(f[i | state[j]], f[i] + 1);
    return f[(1 << k) - 1] <= m;
}
void work()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
        {
            fill(vis, vis + N, false);
            auto t = dfs(i, -1, j);
            if (t.y != -1)
                d[i][j] = t.x - t.y; //t.x是所有关键边的两倍之和 t.y是距离第i个点最远的点 d[i][j]表示第j个食材从点i出发运送完的时间
        }
    int left = 0, right = 2e8; //所有边权和的两倍
    while (left < right)
    {
        int mid = (left + right) >> 1; //二分运送时间
        if (check(mid))                //如果在mid时间内可以让所有酒店得到食材
            right = mid;
        else
            left = mid + 1;
    }
    cout << left;
}
int main()
{
    inp();
    work();
}
