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
    从n行里选m行,使得每一列都至少有一个1，这样的话，所有的食材都确定了出发点
    状压DP
    状态表示
        f[i]表示要送i（i是二进制数，表示状态）食材需要多少检查点
    状态计算
        f[i | state[j]] = min(f[i | state[j]], f[i] + 1)
        i | state[j]表示在i基础上加入检查点j时能送的食材，如果之前已经算过这种状态f[i | state[j]，会让它和f[i]+1做比较，取最小值
 */
using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 105, M = 10, S = 1 << M;

int n, m, k;
int need[N][M];
int h[N], e[2 * N], w[2 * N], ne[2 * N], idx; //链式前向星
int d[N][M];
int f[S], state[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
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
PII dfs(int u, int fa, int v)
{
    PII res(0, -1);
    if (need[u][v])
        res.y = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        auto t = dfs(j, u, v);
        if (t.y != -1)
        {
            res.x += t.x + w[i] * 2;
            res.y = max(res.y, t.y + w[i]);
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
                state[i] |= 1 << j;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 0; i < 1 << k; i++)
        for (int j = 1; j <= n; j++)
            f[i | state[j]] = min(f[i | state[j]], f[i] + 1);
    return f[(1 << k) - 1] <= m;
}
void work()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
        {
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
