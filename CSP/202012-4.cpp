#include "algorithm"
#include "cstring"
#include "iostream"
// #include "map"
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
                d[i][j] = t.x - t.y; //t.x是所有关键边的两倍之和 t.y是距离第i个点最远的点
        }
    int left = 0, right = 2e8; //所有边权和的两倍
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (check(mid))
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
