#include "iostream"
#include "queue"
using namespace std;
/*
    段错误可能是因为BST是链状的超过数组下标
 */
int a[10010];
bool flag[10010];
int depth[10010];
queue<int> q;
int n1, n2;
void insert(int x, int pos)
{
    if (!flag[pos])
    {
        a[pos] = x;
        flag[pos] = true;
        return;
    }
    if (x <= a[pos])
        insert(x, pos * 2);
    else if (x > a[pos])
        insert(x, pos * 2 + 1);
}
int maxn;
void dfs(int x, int cnt)
{
    if (maxn < cnt)
        maxn = cnt;
    depth[x] = cnt;
    if (flag[x * 2])
        dfs(x * 2, cnt + 1);
    if (flag[x * 2 + 1])
        dfs(x * 2 + 1, cnt + 1);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(x, 1);
    }
    // bfs
    dfs(1, 1);
    for (int i = 0; i < 10000; i++)
        if (depth[i] == maxn)
            n1++;
    for (int i = 0; i < 10000; i++)
        if (depth[i] == maxn - 1)
            n2++;
    cout << n1 << " + " << n2 << " = " << n1 + n2;
}
