#include "cstring"
#include "iostream"
using namespace std;
const int N = 1005, M = 20005;
int n, m;
int h[N], h2[N], e[M], ne[M], idx;
bool st[N], st2[N];
void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int h[], bool st[], int x)
{
    st[x] = true;
    for (int i = h[x]; ~i; i = ne[i])
    {
        int y = e[i];
        if (!st[y])
            dfs(h, st, y);
    }
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(h2, -1, sizeof h2);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(h, a, b), add(h2, b, a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(st, st + N, false);
        fill(st2, st2 + N, false);
        dfs(h, st, i);
        dfs(h2, st2, i);
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (st[j] || st2[j]) //如果i能走到j或j能走到i
                cnt++;
        if (cnt == n)
            ans++;
    }
    cout << ans;
}
