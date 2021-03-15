#include "iostream"
using namespace std;
int n, m;
int a[50];
bool vis[10];
void dfs(int x)
{
    if (x == m + 1)
    {
        for (int i = 1; i <= m; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = a[x - 1] + 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(1);
}
